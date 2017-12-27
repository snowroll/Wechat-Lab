/********************************************************************************
** Form generated from reading UI file 'wechat_client.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WECHAT_CLIENT_H
#define UI_WECHAT_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_wechat_client
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *online_label;
    QListView *online_list;
    QPushButton *add_btn;
    QPushButton *chat_btn;
    QPushButton *friends_btn;
    QPushButton *update_btn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *wechat_client)
    {
        if (wechat_client->objectName().isEmpty())
            wechat_client->setObjectName(QStringLiteral("wechat_client"));
        wechat_client->resize(400, 300);
        centralWidget = new QWidget(wechat_client);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 0, 67, 17));
        online_label = new QLabel(centralWidget);
        online_label->setObjectName(QStringLiteral("online_label"));
        online_label->setGeometry(QRect(300, 30, 91, 20));
        online_list = new QListView(centralWidget);
        online_list->setObjectName(QStringLiteral("online_list"));
        online_list->setGeometry(QRect(175, 50, 221, 151));
        add_btn = new QPushButton(centralWidget);
        add_btn->setObjectName(QStringLiteral("add_btn"));
        add_btn->setGeometry(QRect(20, 120, 89, 25));
        chat_btn = new QPushButton(centralWidget);
        chat_btn->setObjectName(QStringLiteral("chat_btn"));
        chat_btn->setGeometry(QRect(20, 160, 89, 25));
        friends_btn = new QPushButton(centralWidget);
        friends_btn->setObjectName(QStringLiteral("friends_btn"));
        friends_btn->setGeometry(QRect(20, 200, 89, 25));
        update_btn = new QPushButton(centralWidget);
        update_btn->setObjectName(QStringLiteral("update_btn"));
        update_btn->setGeometry(QRect(250, 200, 89, 25));
        wechat_client->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(wechat_client);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 28));
        wechat_client->setMenuBar(menuBar);
        mainToolBar = new QToolBar(wechat_client);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        wechat_client->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(wechat_client);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        wechat_client->setStatusBar(statusBar);

        retranslateUi(wechat_client);

        QMetaObject::connectSlotsByName(wechat_client);
    } // setupUi

    void retranslateUi(QMainWindow *wechat_client)
    {
        wechat_client->setWindowTitle(QApplication::translate("wechat_client", "wechat_client", Q_NULLPTR));
        label->setText(QApplication::translate("wechat_client", "Wechat", Q_NULLPTR));
        online_label->setText(QApplication::translate("wechat_client", "online-users", Q_NULLPTR));
        add_btn->setText(QApplication::translate("wechat_client", "add friend", Q_NULLPTR));
        chat_btn->setText(QApplication::translate("wechat_client", "chat", Q_NULLPTR));
        friends_btn->setText(QApplication::translate("wechat_client", "my friends", Q_NULLPTR));
        update_btn->setText(QApplication::translate("wechat_client", "update", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class wechat_client: public Ui_wechat_client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WECHAT_CLIENT_H
