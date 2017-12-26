#include "login.h"
#include "ui_login.h"
#include <QtNetwork/QSctpSocket>
#include <QMessageBox>

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    client = new QTcpSocket(this);
    wechat_view = new wechat_client();
    client->connectToHost(QHostAddress("127.0.0.1"), 8001);
    connect(client, SIGNAL(readyRead()), this, SLOT(readMessage()));//当有消息接受时会触发接收
    connect(this, SIGNAL(login_success()), wechat_view, SLOT(receivelogin()));
}

login::~login()
{
    delete ui;
}

void login::on_login_btn_clicked()
{

    char* msg_info;
    QString username = ui->name_edit->text();
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

    //qDebug() << msg;
}
