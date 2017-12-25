/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QLabel *title;
    QLabel *name_label;
    QLabel *pass_label;
    QLineEdit *name_edit;
    QLineEdit *pass_edit;
    QPushButton *login_btn;
    QPushButton *reg_btn;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(400, 300);
        title = new QLabel(login);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(170, 10, 67, 17));
        name_label = new QLabel(login);
        name_label->setObjectName(QStringLiteral("name_label"));
        name_label->setGeometry(QRect(60, 120, 91, 21));
        pass_label = new QLabel(login);
        pass_label->setObjectName(QStringLiteral("pass_label"));
        pass_label->setGeometry(QRect(60, 160, 81, 21));
        name_edit = new QLineEdit(login);
        name_edit->setObjectName(QStringLiteral("name_edit"));
        name_edit->setGeometry(QRect(170, 120, 131, 21));
        pass_edit = new QLineEdit(login);
        pass_edit->setObjectName(QStringLiteral("pass_edit"));
        pass_edit->setGeometry(QRect(170, 160, 131, 21));
        login_btn = new QPushButton(login);
        login_btn->setObjectName(QStringLiteral("login_btn"));
        login_btn->setGeometry(QRect(90, 220, 89, 25));
        reg_btn = new QPushButton(login);
        reg_btn->setObjectName(QStringLiteral("reg_btn"));
        reg_btn->setGeometry(QRect(210, 220, 89, 25));

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Form", Q_NULLPTR));
        title->setText(QApplication::translate("login", "wechat", Q_NULLPTR));
        name_label->setText(QApplication::translate("login", "user name:", Q_NULLPTR));
        pass_label->setText(QApplication::translate("login", "password:", Q_NULLPTR));
        login_btn->setText(QApplication::translate("login", "login", Q_NULLPTR));
        reg_btn->setText(QApplication::translate("login", "register", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
