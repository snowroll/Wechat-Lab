#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QtNetwork/QTcpSocket>
#include "wechat_client.h"
#include "ui_wechat_client.h"
#include "chat.h"

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

signals:
    void login_success();
    void update_data(QString);
    void receive_msg(QString);

private slots:
    void on_login_btn_clicked();
    void on_reg_btn_clicked();
    void readMessage();
    void receiveupdate();
    void msg_send(QString);
    void update_chat_name(QString);
    void erase_name();  //erase other name
    void update_name(QString);  //update other name

private:
    Ui::login *ui;
    QTcpSocket *client;
    wechat_client* wechat_view;
    chat* chat_view;
    QString message;
    QString cur_chat_name;
    QString my_name;
    quint16 blockSize;  //store data size
};

#endif // LOGIN_H
