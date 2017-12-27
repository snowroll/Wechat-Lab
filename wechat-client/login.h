#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QtNetwork/QTcpSocket>
#include "wechat_client.h"
#include "ui_wechat_client.h"

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

private slots:
    void on_login_btn_clicked();
    void on_reg_btn_clicked();
    void readMessage();
    void receiveupdate();

private:
    Ui::login *ui;
    QTcpSocket *client;
    wechat_client* wechat_view;
    QString message;
    quint16 blockSize;  //store data size
};

#endif // LOGIN_H
