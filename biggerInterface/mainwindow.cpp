#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(User user,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
     ui->setupUi(this);
     currentUser = user;
     ui->UserName->setText(user.getName());

    //Заполнение отладочными данными
    Dialog d1("Alice","Bob");
    d1.addMessage(Message("Alice","Bob","Hi, Bob!"));
    d1.addMessage(Message("Bob","Alice","И тебе привет, Алиса"));
    dialogs.push_back(d1);

    findCurUserDialogs();
    for( int i = 0; i < curDialogs.size(); i++){
        if(dialogs[curDialogs[i]].getName1() == currentUser.getName())
            ui->userList->addItem(dialogs[curDialogs[i]].getName2());
        else
            dialogs[curDialogs[i]].getName2();
    }



}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_enterButton_clicked()
{
    QString text = ui->msgEdit->document()->toPlainText();
    QString reciever;
    if(dialogs[curDialog].getName1()!= currentUser.getName())
        reciever = dialogs[curDialog].getName1();
    else
        reciever = dialogs[curDialog].getName2();
    dialogs[curDialog].addMessage(Message(currentUser.getName(),reciever,text));
    updMsgs();
}

void MainWindow::findCurUserDialogs()
{
    for(int i = 0; i < dialogs.size();i++)
        if(dialogs[i].getName1() == currentUser.getName() || dialogs[i].getName2() == currentUser.getName())
            curDialogs.push_back(i);
}

void MainWindow::updMsgs()
{
    ui->msgList->clear();
    for(int i = 0; i < dialogs[curDialog].size();i++){
        QListWidgetItem *it = new QListWidgetItem(dialogs[curDialog].getMsgs()[i].getText());
        if(dialogs[curDialog].getMsgs()[i].getSender() == currentUser.getName())
            it->setTextAlignment(2);
        else
            it->setTextAlignment(1);
        ui->msgList->addItem(it);
    }
}


void MainWindow::on_userList_itemClicked(QListWidgetItem *item)
{
    curDialog = curDialogs[ui->userList->row(item)];
    updMsgs();
}

