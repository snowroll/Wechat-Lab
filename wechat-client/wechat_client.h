#ifndef WECHAT_CLIENT_H
#define WECHAT_CLIENT_H

#include <QMainWindow>
#include <QtNetwork/QTcpSocket>


namespace Ui {
class wechat_client;
}

class wechat_client : public QMainWindow
{
    Q_OBJECT

public:
    explicit wechat_client(QWidget *parent = 0);
    ~wechat_client();

signals:
    void update_list();

private slots:
    void receivelogin();
    void on_update_btn_clicked();
    void readyupdate(QString);

private:
    Ui::wechat_client *ui;
};

#endif // WECHAT_CLIENT_H
