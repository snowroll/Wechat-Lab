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


}

login::~login()
{
    delete ui;
}

void login::on_login_btn_clicked()
{

    char* msg_name; char* msg_pass;
    QString username = ui->name_edit->text();
    QString password = ui->pass_edit->text();
    QByteArray QB_name = username.toLatin1();
    msg_name = QB_name.data();
    QByteArray QB_pass = password.toLatin1();
    msg_pass = QB_pass.data();
    char* signal_login = "login";
    client->write(signal_login);

    //client->write(msg_pass);
    //client->write(msg_name);

}

void login::on_reg_btn_clicked()
{

}
