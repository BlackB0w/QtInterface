#include "user.h"

User::User(QString n, QString l, QString p)
{
    name = n;
    login = l;
    pass = p;
}

User::User()
{
    name = "stub";
    login = "stub";
    pass = "stub";
}

const QString &User::getName() const
{
    return name;
}

void User::setName(const QString &newName)
{
    name = newName;
}

const QString &User::getLogin() const
{
    return login;
}

void User::setLogin(const QString &newLogin)
{
    login = newLogin;
}

const QString &User::getPass() const
{
    return pass;
}

void User::setPass(const QString &newPass)
{
    pass = newPass;
}

