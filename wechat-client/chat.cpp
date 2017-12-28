#include "chat.h"
#include "ui_chat.h"
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>

chat::chat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chat)
{
    ui->setupUi(this);
    ui->open_file_btn->setEnabled(true);
    ui->send_file_btn->setEnabled(false);
    ui->progress_bar->setValue(0);
}

chat::~chat()
{
    delete ui;
}






void on_open_file_btn_clicked();

void on_send_file_btn_clicked();

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
        QString show_msg = "-me-:";
        show_msg += msg;
        show_msg += "\n";
        ui->chat_msg->insertPlainText(show_msg);
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
    QString show_msg = lst[3] + "\n";
    ui->chat_msg->insertPlainText(show_msg);
    ui->chat_msg->moveCursor(QTextCursor::End);
}

void chat::on_open_file_btn_clicked()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "/home");
    //QString theFileName = fileName.right(fileName.size() - fileName.lastIndexOf('/') - 1);
    qDebug()  << "fileName: " << fileName;
    emit send_file_name(fileName);
    ui->send_file_btn->setEnabled(true);
}

void chat::on_send_file_btn_clicked()
{
    emit send_file(fileName);
    ui->send_btn->setEnabled(false);
}

void chat::updClintProgress(qint64 totalBytes, qint64 writeBytes){
    qDebug() << "update client progress" ;
    qApp->processEvents();
    ui->progress_bar->setMaximum(totalBytes);
    ui->progress_bar->setValue(writeBytes);
    if(writeBytes == totalBytes){
        QMessageBox::information(this, "success", "file transfer successfully");
    }
}

void chat::open_fail(){
    QMessageBox::information(this, "error", "file open failed");
}
