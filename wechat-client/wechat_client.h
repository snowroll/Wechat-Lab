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


private slots:
    void on_send_button_clicked();

    void on_link_button_clicked();

private:
    Ui::wechat_client *ui;

};

#endif // WECHAT_CLIENT_H
