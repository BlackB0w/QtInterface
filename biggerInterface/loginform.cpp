#include "loginform.h"
#include "ui_loginform.h"

LoginForm::LoginForm(QVector<User> users,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
    usrs = users;
    ui->errorLabel->hide();
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_pushButton_clicked()
{
    bool isInList = false;
    int i = 0;
    for(; i < usrs.size(); i++)
        if (ui->login->text() == usrs[i].getLogin() && ui->pass->text() == usrs[i].getPass()){
            isInList = true;
            break;
        }
    if(isInList){
        MainWindow * mw= new MainWindow(usrs[i]);
        mw->show();
        this->close();
    } else{
       ui->errorLabel->show();
    }
}

