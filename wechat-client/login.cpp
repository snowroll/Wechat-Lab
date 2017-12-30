#include "login.h"
#include "ui_login.h"
#include <QtNetwork/QSctpSocket>
#include <QTextStream>
#include <QMessageBox>
#include <QFile>
/*  file header file  */
#include <QFileDialog>
#include <QTcpServer>
#include <QDebug>
#include "QObject"
#include <QTcpSocket>
#include <QUdpSocket>
#include <QNetworkInterface>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <qtcpserver.h>

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->pass_edit->setEchoMode(QLineEdit::Password);
    client = new QTcpSocket(this);
    wechat_view = new wechat_client();
    chat_view = new chat();
    client->connectToHost(QHostAddress("127.0.0.1"), 8001);

    /*  init  */
    totalBytes = 0; recevBytes = 0; fileNameSize = 0;

    connect(client, SIGNAL(readyRead()), this, SLOT(readMessage()));//当有消息接受时会触发接收
    connect(this, SIGNAL(login_success()), wechat_view, SLOT(receivelogin()));
    connect(wechat_view, SIGNAL(update_list()), this, SLOT(receiveupdate()));  //update give to soket then send to server
    connect(this, SIGNAL(update_data(QString)), wechat_view, SLOT(readyupdate(QString)));  //receive data from server then update ui
    connect(wechat_view, SIGNAL(chat_begin(QString)), chat_view, SLOT(ready_chat(QString)));
    connect(wechat_view, SIGNAL(chat_begin(QString)), this, SLOT(update_chat_name(QString)));
    connect(chat_view, SIGNAL(exit()), wechat_view, SLOT(reshow()));
    connect(chat_view, SIGNAL(exit()), this,  SLOT(erase_name()));
    connect(chat_view, SIGNAL(send_msg(QString)), this, SLOT(msg_send(QString)));

    /*  receive msg  */
    connect(this, SIGNAL(receive_msg(QString)), chat_view, SLOT(chat_ing(QString)));
    connect(chat_view, SIGNAL(update_chat_name(QString)), this, SLOT(update_name(QString)));

    /*  add friend  */
    connect(wechat_view, SIGNAL(add_friend(QString)), this, SLOT(friend_add(QString)));
    connect(this, SIGNAL(add_res(QString)), wechat_view, SLOT(res_add(QString)));

    /*  show friend  */
    connect(wechat_view, SIGNAL(update_friend_list()), this, SLOT(friend_list_update()));
    connect(this, SIGNAL(show_flist(QString)), wechat_view, SLOT(flist_show(QString)));

    /*  send file  */
    connect(chat_view, SIGNAL(send_file_name(QString)), this, SLOT(update_file_name(QString)));
    connect(chat_view, SIGNAL(send_file(QString)), this, SLOT(sendMsg()));
    connect(this, SIGNAL(not_open_file()), chat_view, SLOT(open_fail()));
    connect(this, SIGNAL(update_pro_para(qint64,qint64)), chat_view, SLOT(updClintProgress(qint64, qint64)));

    /*  rec file  */
    connect(this, SIGNAL(receive_file(QString)), chat_view, SLOT(file_ing(QString)));
    connect(this, SIGNAL(rec_file()), this, SLOT(readMsg()));

}

login::~login()
{
    delete ui;
}

void login::on_login_btn_clicked()
{

    char* msg_info;
    QString username = ui->name_edit->text();
    my_name = username;  //copy name to local varible
    QString password = ui->pass_edit->text();
    QString login_info = "login," + username + "," + password;
    QByteArray QB_info = login_info.toLatin1();
    msg_info = QB_info.data();
    if(username == "bye"){
        char* bye = "bye";
        client->write(bye);
    }
    else
        client->write(msg_info);
}

void login::on_reg_btn_clicked()
{
    char* msg_info;
    QString username = ui->name_edit->text();
    QString password = ui->pass_edit->text();
    QString login_info = "register," + username + "," + password;
    QByteArray QB_info = login_info.toLatin1();
    msg_info = QB_info.data();
    client->write(msg_info);
}

void login::readMessage()
{
    QString msg = client->readAll();
    QTextStream cout(stdout, QIODevice::WriteOnly);
    cout << msg << endl;
    char buf[1024];
    client->read(buf, 1024);


    /*   deal login & register    */
    if(msg == "ok"){
        emit login_success();
        this->close();
    }
    else if(msg == "password_error"){
        QMessageBox::information(this, "warnning", "password error");
    }
    else if(msg == "user_not_exist"){
        QMessageBox::information(this, "warnning", "user not exist");
    }
    else if(msg == "user_existed"){
        QMessageBox::information(this, "warnning", "user has existed");
    }
    else if(msg == "success"){
        QMessageBox::information(this, "success", "register success");
    }
    else if(msg == "addhas"){
        QString str = "has";
        emit add_res(str);
    }
    else if(msg == "addsucc"){
        QString str = "success";
        emit add_res(str);
    }

    /*    deal update info    */
    QString tag = msg.mid(0, 6);
    if(tag == "update"){
        QString names = msg.mid(7);
        //QTextStream cout(stdout, QIODevice::WriteOnly);
        //cout << names << endl;
        emit update_data(names);
    }

    tag = msg.mid(0, 4);
    if(tag == "send"){
        emit receive_msg(msg);
    }
    else if(tag == "file"){
        emit receive_file(msg);
    }

    /*   show flist    */
    tag = msg.mid(0, 5);
    if(tag == "flist"){
        emit show_flist(msg);
    }

    /*  file buffer  */
    emit rec_file();

    cout << msg << endl;
}

void login::receiveupdate(){
    qDebug("receive update signal");
    char* update_info = "update";
    client->write(update_info);
}

void login::msg_send(QString msg){
    char* msg_final;
    QString final_msg = "send,";
    final_msg += cur_chat_name;
    final_msg += ",";
    final_msg += my_name;
    final_msg += ",";
    final_msg += msg;
    QByteArray QB_info = final_msg.toLatin1();
    msg_final = QB_info.data();
    client->write(msg_final);
}

void login::update_chat_name(QString names){
    cur_chat_name = names;
}

void login::erase_name(){
    cur_chat_name = "";
}

void login::update_name(QString name){
    cur_chat_name = name;
}

void login::friend_add(QString msg){
    char* msg_final;
    QString final_msg = msg;
    final_msg += ",";
    final_msg += my_name;
    QByteArray QB_info = final_msg.toLatin1();
    msg_final = QB_info.data();
    client->write(msg_final);
}

void login::friend_list_update(){
    char* msg_final;
    QString final_msg = "flist," + my_name;
    QByteArray QB_info = final_msg.toLatin1();
    msg_final = QB_info.data();
    client->write(msg_final);
}

void login::sendMsg(){  //send file
    qDebug() << "--- send file begin ---";
    connect(client, SIGNAL(bytesWritten(qint64)), this, SLOT(update_pro_singal(qint64)));
    locFile = new QFile(fileName);
    if(!locFile->open((QFile::ReadOnly))){
        emit not_open_file();
        return;
    }
    totalBytes = locFile->size();  //file tatal size()
    qDebug() << "filetotalbytes:" << totalBytes;

    QString curFile = fileName.right(fileName.size() - fileName.lastIndexOf('/') - 1);
    qDebug() << "curFile: " << curFile;


    /*  send file pre in order to receive*/
    char* file_send_pre;
    QString final_msg = "file,";
    final_msg += cur_chat_name;
    final_msg += ",";
    final_msg += my_name;
    final_msg += ",";
    final_msg += curFile;
    QByteArray QB_info = final_msg.toLatin1();
    file_send_pre = QB_info.data();
    client->write(file_send_pre);

    QDataStream sendOut(&outBlock, QIODevice::WriteOnly);
    sendOut.setVersion(QDataStream::Qt_4_7);
    //time.start();


    sendOut << qint64(0) << qint64(0) << curFile;
    totalBytes += outBlock.size();  //file name size + real size
    sendOut.device()->seek(0);
    sendOut << totalBytes << qint64((outBlock.size() - sizeof(qint64)*2));
    tobeWriteBytes = totalBytes - client->write(outBlock);  //send data in buffer
    client->waitForBytesWritten();
    qDebug() << "tobeWriteBytes:" << tobeWriteBytes;
    qDebug() << "outBlock:" << outBlock;
    outBlock.resize(0);
}


void login::update_file_name(QString fname){
    fileName = fname;
    qDebug() << "receive filename is " << fname;
}

void login::update_pro_singal(qint64 bytenum){
    qDebug() << "update progress";
    if(tobeWriteBytes > 0){  //没发送完
        qDebug() << "not send complete";
        outBlock = locFile->read(qMin(tobeWriteBytes, payloadSize));//每次最多发送64k大小。
        tobeWriteBytes -= (int)client->write(outBlock);
        writeBytes += (totalBytes - tobeWriteBytes);//已经发送了的。
        outBlock.resize(0);
    }else {
        locFile->close();
    }
    emit update_pro_para(totalBytes, writeBytes);


    qDebug() << "writeBytes:"<< writeBytes;
    qDebug() << "totalBytes:" << totalBytes;

    if(writeBytes == totalBytes){
        locFile->close();
        qDebug() << "file send end";
    }
}

void login::readMsg(){
    qDebug() << "-----------readMsg start-----------";
    QDataStream in(client);
    in.setVersion(QDataStream::Qt_4_7);

    //float useTime = Time.elapsed();
    if(recevBytes <= sizeof(qint64)*2){
        if((client->bytesAvailable() >= sizeof(qint64)*2) && fileNameSize == 0){
            //接收数据总大小信息和数据文件名大小。
            in >> totalBytes >> fileNameSize;
            qDebug() << "totalBytes:" << totalBytes;
            qDebug() << "fileNameSize:" << fileNameSize;
            recevBytes += sizeof(qint64)*2;
            qDebug() << "1recevBytes:" << recevBytes;
        }
        if((client->bytesAvailable() >= fileNameSize) && (fileNameSize != 0)){
            //开始接收文件，并建立文件。
            in >> fileName;
            qDebug() << "FileName:" << fileName;
            recevBytes += fileNameSize;
            qDebug() << "2recevBytes:" << recevBytes;
            if(!locFile->open(QFile::WriteOnly)){
                QMessageBox::warning(this,tr("应用程序"),tr("无法读取文件%1: \n%2").arg(fileName).arg(locFile->errorString()));
                return;
            }
        }else{
            return;
        }
    }

    qDebug() << "-----------BytesArray write newFile of start-----------";
    if(recevBytes < totalBytes){
        recevBytes += client->bytesAvailable();        //把缓存区的内容写入文件。
        inBlock = client->readAll();
        locFile->write(inBlock);
        inBlock.resize(0);                             //清空缓存区
    }
    /* set bar later */
   // ui->progressBar->setMaximum(totalBytes);
   // ui->progressBar->setValue(recevBytes);//设置进度条的进度
    qDebug() << "recevBytes:" << recevBytes;
    qDebug() << "totalBytes:" << totalBytes;
    if(recevBytes == totalBytes){
        locFile->close();
        //cClint->close();
       // ui->label->setText(tr("接收文件 %1完毕 ").arg(FileName));
    }
}

void login::hasPendingFile(QString fileName){
    int btn = QMessageBox::information(this, tr("receive file"), tr("file receive").arg(fileName),
                                       QMessageBox::Yes,QMessageBox::No);
   if(btn == QMessageBox::Yes){
       QString name = QFileDialog::getSaveFileName(0,tr("保存文件"),fileName);
       if(!name.isEmpty()){
           //Dialog *clint = new Dialog(this);
           //setFileName(name);
           update_file_name(name);
           //setHostaddr(QHostAddress(serAddress));//默认一台电脑用。
       }
   }
   else{
//      SendRefuse(refuse);
//       sleep(2);
//       on_cClosebtn_clicked();
   }
}
