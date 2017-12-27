#include "wechat_client.h"
#include "ui_wechat_client.h"
#include "login.h"
#include <QtNetwork/QSctpSocket>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QMessageBox>
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
    if(ui->online_label->text() == "Friend-list")
        ui->online_label->setText("online-users");
    emit update_list();
}

void wechat_client::readyupdate(QString names){
    QStringList lst;
    lst = names.split(QRegExp("[,]"));
    QStringListModel *model = new QStringListModel(lst);
    ui->online_list->setModel(model);
}

void wechat_client::on_chat_btn_clicked()
{
    QString chat_name = ui->name_edit->text();
    if(chat_name == NULL){  //not select user
        QMessageBox::information(this, "warning", "please input one person to chat");
    }
    else{
        emit chat_begin(chat_name);
        this->close();
    }

}

void wechat_client::reshow(){
    this->show();
}

void wechat_client::on_add_btn_clicked()
{
    QString chat_name = ui->name_edit->text();
    if(chat_name == NULL){  //not select user
        QMessageBox::information(this, "warning", "please input one person to chat");
    }
    else{
        QString add_info = "add,";
        add_info += chat_name;
        emit add_friend(add_info);
    }
}

void wechat_client::res_add(QString msg){
    if(msg == "has")
        QMessageBox::information(this, "warning", "friend has been added");
    else
        QMessageBox::information(this, "success", "add friend success");
}

void wechat_client::on_friends_btn_clicked()
{
    ui->online_label->setText("Friend-list");
    emit update_friend_list();
}

void wechat_client::flist_show(QString msg){
    if(msg == "flist")
        QMessageBox::information(this, "warnning", "you have no friend yet");
    else{
        QString friends = msg.mid(5);
        QStringList lst;
        lst = friends.split(QRegExp("[,]"));  //only one person maybe error??
        QStringListModel *model = new QStringListModel(lst);
        ui->online_list->setModel(model);
    }
}
