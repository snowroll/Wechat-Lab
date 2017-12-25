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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_wechat_client
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *send_button;
    QTextEdit *info_edit;
    QPushButton *link_button;
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
        label->setGeometry(QRect(10, 0, 67, 17));
        send_button = new QPushButton(centralWidget);
        send_button->setObjectName(QStringLiteral("send_button"));
        send_button->setGeometry(QRect(190, 120, 89, 25));
        info_edit = new QTextEdit(centralWidget);
        info_edit->setObjectName(QStringLiteral("info_edit"));
        info_edit->setGeometry(QRect(30, 60, 151, 91));
        link_button = new QPushButton(centralWidget);
        link_button->setObjectName(QStringLiteral("link_button"));
        link_button->setGeometry(QRect(190, 80, 89, 25));
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
        send_button->setText(QApplication::translate("wechat_client", "send", Q_NULLPTR));
        link_button->setText(QApplication::translate("wechat_client", "connect", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class wechat_client: public Ui_wechat_client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WECHAT_CLIENT_H
