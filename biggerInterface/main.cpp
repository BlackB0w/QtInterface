#include "mainwindow.h"
#include <loginform.h>
#include <user.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QVector <User> userlist;
    userlist.push_back(User("Alice","Alice01","010101"));
    userlist.push_back(User("Bob","imBob","2222"));
    userlist.push_back(User("Conrad","crcr","333"));

    LoginForm lf(userlist);
    lf.show();
    return a.exec();
}
