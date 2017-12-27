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

private slots:
    void ready_chat(QString);

    void on_exit_btn_clicked();
    void chat_ing(QString);
    void on_send_btn_clicked();

private:
    Ui::chat *ui;
};

#endif // CHAT_H
