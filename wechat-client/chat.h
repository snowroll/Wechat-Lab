#ifndef CHAT_H
#define CHAT_H

#include <QWidget>


namespace Ui {
class chat;
}

class chat : public QWidget
{
    Q_OBJECT

public:
    explicit chat(QWidget *parent = 0);
    ~chat();

signals:
    void exit();
    void send_msg(QString);
    void update_chat_name(QString);
    void send_file_name(QString);
    void send_file(QString);


   // void sendFileName(QString);

private slots:
    void ready_chat(QString);
    void on_exit_btn_clicked();
    void chat_ing(QString);
    void on_send_btn_clicked();


    /* file send */
    void on_open_file_btn_clicked();
    void on_send_file_btn_clicked();
    void updClintProgress(qint64, qint64);  //update progress
    void open_fail();

    void file_ing(QString);

private:
    Ui::chat *ui;
    QString fileName;
};

#endif // CHAT_H
