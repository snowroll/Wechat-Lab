#include "wechat_client.h"
#include "ui_wechat_client.h"
#include "login.h"
#include <QtNetwork/QSctpSocket>
#include <QStringListModel>
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

void wechat_client::receivelogin()
{
    this->show();
}


void wechat_client::on_update_btn_clicked()
{
    emit update_list();
}

void wechat_client::readyupdate(QString names){
    QStringList lst;
    lst = names.split(QRegExp("[,]"));
    QStringListModel *model = new QStringListModel(lst);
    ui->online_list->setModel(model);
}
