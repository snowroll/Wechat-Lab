#include "wechat_client.h"
#include "ui_wechat_client.h"
#include <QtNetwork/QSctpSocket>
#include <string.h>

wechat_client::wechat_client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::wechat_client)
{
    ui->setupUi(this);
}

wechat_client::~wechat_client()
{
    delete ui;
}

void wechat_client::on_send_button_clicked()
{
    char* msg_ch;
    QString msg = ui->info_edit->toPlainText();
    QByteArray ba = msg.toLatin1();
    msg_ch=ba.data();
    //client->write(msg_ch);
}

void wechat_client::on_link_button_clicked()
{
    //client->connectToHost(QHostAddress("127.0.0.1"), 8001);
    //client->waitForConnected(400);
//    if(client->state() == QAbstractSocket::ConnectedState)
//        ui->link_button->setText("connected");
}

void wechat_client::receivelogin()
{
    this->show();
}
