#include "chat.h"
#include "ui_chat.h"
#include <QMessageBox>

chat::chat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chat)
{
    ui->setupUi(this);
}

chat::~chat()
{
    delete ui;
}

void chat::ready_chat(QString names)
{
    this->show();
    ui->friend_name->setText(names);
}

void chat::on_exit_btn_clicked()
{
    emit exit();
    this->close();
}

void chat::on_send_btn_clicked()
{
    QString msg = ui->input_edit->toPlainText();
    if(msg == NULL){
        QMessageBox::information(this, "warnning", "info cann't be empty");
    }
    else{
        ui->chat_msg->insertPlainText(msg);
        ui->chat_msg->moveCursor(QTextCursor::End);
        emit send_msg(msg);
    }
}

void chat::chat_ing(QString msg){
    this->show();
    QStringList lst;
    lst = msg.split(QRegExp("[,]"));  // send  receive_name send_name msg
    emit update_chat_name(lst[2]);
    ui->friend_name->setText(lst[2]);
    ui->chat_msg->insertPlainText(lst[3]);
    ui->chat_msg->moveCursor(QTextCursor::End);
}
