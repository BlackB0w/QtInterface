#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>
#include <user.h>
#include<mainwindow.h>
namespace Ui {
class LoginForm;
}

class LoginForm : public QWidget
{
    Q_OBJECT

public:
    explicit LoginForm(QVector<User> users, QWidget *parent = nullptr);
    ~LoginForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LoginForm *ui;
    QVector<User> usrs;
};

#endif // LOGINFORM_H
