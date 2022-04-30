#ifndef USER_H
#define USER_H
#include <QString>

class User
{
    QString name;
    QString login;
    QString pass;
public:
    User(QString n, QString l, QString p);
    User();
    const QString &getName() const;
    void setName(const QString &newName);
    const QString &getLogin() const;
    void setLogin(const QString &newLogin);
    const QString &getPass() const;
    void setPass(const QString &newPass);
};

#endif // USER_H
