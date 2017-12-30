#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QtNetwork/QTcpSocket>
#include <QAbstractSocket>
#include <QDialog>
#include <QTime>
#include "wechat_client.h"
#include "ui_wechat_client.h"
#include "chat.h"

class QTcpServer;
class QFile;
class QTcpSoket;

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
    void receive_file(QString);
    void add_res(QString);
    void show_flist(QString);

    void not_open_file();
    void update_pro_para(qint64, qint64);
    /* file receive */
    void rec_file();


protected:
    /*  file send  */
    void SendFileName(QString fileName);  //not realize

    void hasPendingFile(QString fileName);

private slots:
    void on_login_btn_clicked();
    void on_reg_btn_clicked();
    void readMessage();
    void receiveupdate();
    void msg_send(QString);
    void update_chat_name(QString);
    void erase_name();  //erase other name
    void update_name(QString);  //update other name
    void friend_list_update();
    void friend_add(QString);

    /*  file send  */
    void sendMsg();
    void update_file_name(QString);
    void update_pro_singal(qint64);

    /*  file receive */
    void readMsg();
   // void processPendingDatarams();



private:
    Ui::login *ui;
    QTcpSocket *client;
    wechat_client* wechat_view;
    chat* chat_view;
    QString message;
    QString cur_chat_name;
    QString my_name;
    quint16 blockSize;  //store data size

    /* file */
    QFile *locFile;
    QTime time;

    qint64 totalBytes;
    qint64 writeBytes;
    qint64 tobeWriteBytes;
    qint64 payloadSize;  //be init first varible
    qint64 recevBytes;  //receive file bytes
    qint64 fileNameSize;  //receive file name size

    QString fileName;
    QByteArray outBlock;
    QByteArray inBlock;


};

#endif // LOGIN_H
