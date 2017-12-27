#include "login.h"
#include "ui_login.h"
#include <QtNetwork/QSctpSocket>
#include <QTextStream>
#include <QMessageBox>

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    client = new QTcpSocket(this);
    wechat_view = new wechat_client();
    chat_view = new chat();
    client->connectToHost(QHostAddress("127.0.0.1"), 8001);
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
        QTextStream cout(stdout, QIODevice::WriteOnly);
        cout << names << endl;
        emit update_data(names);
    }

    tag = msg.mid(0, 4);
    if(tag == "send"){
        emit receive_msg(msg);
    }

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
