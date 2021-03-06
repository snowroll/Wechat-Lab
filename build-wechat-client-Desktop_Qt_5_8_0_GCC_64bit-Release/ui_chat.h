/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chat
{
public:
    QTextBrowser *chat_msg;
    QTextEdit *input_edit;
    QPushButton *send_btn;
    QPushButton *exit_btn;
    QLabel *friend_name;
    QPushButton *send_file_btn;
    QPushButton *open_file_btn;
    QProgressBar *progress_bar;

    void setupUi(QWidget *chat)
    {
        if (chat->objectName().isEmpty())
            chat->setObjectName(QStringLiteral("chat"));
        chat->resize(400, 300);
        chat_msg = new QTextBrowser(chat);
        chat_msg->setObjectName(QStringLiteral("chat_msg"));
        chat_msg->setGeometry(QRect(30, 30, 281, 161));
        input_edit = new QTextEdit(chat);
        input_edit->setObjectName(QStringLiteral("input_edit"));
        input_edit->setGeometry(QRect(30, 200, 281, 51));
        send_btn = new QPushButton(chat);
        send_btn->setObjectName(QStringLiteral("send_btn"));
        send_btn->setGeometry(QRect(120, 260, 89, 25));
        exit_btn = new QPushButton(chat);
        exit_btn->setObjectName(QStringLiteral("exit_btn"));
        exit_btn->setGeometry(QRect(220, 260, 89, 25));
        friend_name = new QLabel(chat);
        friend_name->setObjectName(QStringLiteral("friend_name"));
        friend_name->setGeometry(QRect(30, 10, 67, 17));
        send_file_btn = new QPushButton(chat);
        send_file_btn->setObjectName(QStringLiteral("send_file_btn"));
        send_file_btn->setGeometry(QRect(320, 140, 81, 25));
        open_file_btn = new QPushButton(chat);
        open_file_btn->setObjectName(QStringLiteral("open_file_btn"));
        open_file_btn->setGeometry(QRect(320, 100, 81, 25));
        progress_bar = new QProgressBar(chat);
        progress_bar->setObjectName(QStringLiteral("progress_bar"));
        progress_bar->setGeometry(QRect(320, 180, 81, 23));
        progress_bar->setValue(24);

        retranslateUi(chat);

        QMetaObject::connectSlotsByName(chat);
    } // setupUi

    void retranslateUi(QWidget *chat)
    {
        chat->setWindowTitle(QApplication::translate("chat", "Form", Q_NULLPTR));
        send_btn->setText(QApplication::translate("chat", "send", Q_NULLPTR));
        exit_btn->setText(QApplication::translate("chat", "exit", Q_NULLPTR));
        friend_name->setText(QApplication::translate("chat", "friends", Q_NULLPTR));
        send_file_btn->setText(QApplication::translate("chat", "send file", Q_NULLPTR));
        open_file_btn->setText(QApplication::translate("chat", "open file", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class chat: public Ui_chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
