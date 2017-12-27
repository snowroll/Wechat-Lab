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
    void chat_begin(QString);
    void add_friend(QString);
    void update_friend_list();

private slots:
    void receivelogin();
    void on_update_btn_clicked();
    void readyupdate(QString);
    void reshow();
    void on_chat_btn_clicked();
    void res_add(QString);
    void on_add_btn_clicked();
    void flist_show(QString);
    void on_friends_btn_clicked();

private:
    Ui::wechat_client *ui;
};

#endif // WECHAT_CLIENT_H
