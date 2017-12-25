#include "wechat_client.h"
#include "login.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login login_view;
    login_view.show();
    return a.exec();
}
