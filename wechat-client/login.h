#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QtNetwork/QTcpSocket>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_login_btn_clicked();
    void on_reg_btn_clicked();
    //void sendMessage();
    void readMessage();


private:
    Ui::login *ui;
    QTcpSocket *client;
    QString message;
    quint16 blockSize;  //store data size
};

#endif // LOGIN_H