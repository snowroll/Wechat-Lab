#include "login.h"
#include "ui_login.h"
#include <QtNetwork/QSctpSocket>

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    client = new QTcpSocket(this);
    client->connectToHost(QHostAddress("127.0.0.1"), 8001);
    connect(client, SIGNAL(readyRead()), this, SLOT(readMessage()));//当有消息接受时会触发接收
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
    //char* signal_login = "login";
    if(username == "bye"){
        char* bye = "bye";
        client->write(bye);
    }
    else
        client->write(msg_info);
    //to do  continues to send will block tcp
    //client->write(msg_pass);
    //client->write(msg_name);

}

void login::on_reg_btn_clicked()
{

}

void login::readMessage()
{
    QString msg = client->readAll();
    char buf[1024];
    client->read(buf, 1024);
    qDebug() << msg;
}