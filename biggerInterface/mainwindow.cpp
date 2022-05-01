#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QVector<User> userList, User user,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentUser = user;
    this->userList = userList;

    QFile scrollFile("..//biggerinterface//qss//scrollVertical.qss");
    scrollFile.open(QFile::ReadOnly);
    QString scrollStyle = scrollFile.readAll();
    scrollFile.close();
    ui->msgList->verticalScrollBar()->setStyleSheet(scrollStyle);
    ui->userList->verticalScrollBar()->setStyleSheet(scrollStyle);
    ui->UserName->setText(user.getName());
    ui->msgEdit->hide();
    ui->msgList->hide();
    ui->enterButton->hide();
    ui->msgList->setWordWrap(true);

    //Заполнение отладочными данными
    Dialog d1("Alice","Bob");
    d1.addMessage(Message("Alice","Bob","Hi, Bob!"));
    d1.addMessage(Message("Bob","Alice","И тебе привет, Алиса"));
    Dialog d2("Conrad","Bob");
    d2.addMessage(Message("Conrad","Bob","Hallo, Bob!"));
    d2.addMessage(Message("Bob","Conrad","Здрасте"));
    dialogs.push_back(d1);
    dialogs.push_back(d2);
    updDialogs();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_enterButton_clicked()
{
    QString text = ui->msgEdit->document()->toPlainText();
    ui->msgEdit->clear();
    if(text != ""){
        QString reciever;
        if(dialogs[curDialog].getName1()!= currentUser.getName())
            reciever = dialogs[curDialog].getName1();
        else
            reciever = dialogs[curDialog].getName2();
        dialogs[curDialog].addMessage(Message(currentUser.getName(),reciever,text));
        updMsgs();
    }
}

void MainWindow::findCurUserDialogs()
{
    curDialogs.clear();
    for(int i = 0; i < dialogs.size();i++)
        if(dialogs[i].getName1() == currentUser.getName() || dialogs[i].getName2() == currentUser.getName())
            curDialogs.push_back(i);
}

void MainWindow::updMsgs()
{
    ui->msgList->clear();
    for(int i = 0; i < dialogs[curDialog].size();i++){
        QListWidgetItem *it;
        if(dialogs[curDialog].getMsgs()[i].getSender() == currentUser.getName())
        {
            it = new QListWidgetItem("Вы: "+ dialogs[curDialog].getMsgs()[i].getText());
            it->setTextAlignment(2);
        }
        else
        {
            it = new QListWidgetItem(dialogs[curDialog].getMsgs()[i].getSender() +": "
                                        +dialogs[curDialog].getMsgs()[i].getText());
            it->setTextAlignment(1);
        }
        ui->msgList->addItem(it);
        ui->msgList->setCurrentItem(it);
    }
}

void MainWindow::updDialogs()
{
    findCurUserDialogs();
    ui->userList->clear();
    for( int i = 0; i < curDialogs.size(); i++){
        if(dialogs[curDialogs[i]].getName1() == currentUser.getName())
            ui->userList->addItem(dialogs[curDialogs[i]].getName2());
        else
            ui->userList->addItem(dialogs[curDialogs[i]].getName1());
    }
}


void MainWindow::on_userList_itemClicked(QListWidgetItem *item)
{
    curDialog = curDialogs[ui->userList->row(item)];
    ui->msgEdit->show();
    ui->msgList->show();
    ui->enterButton->show();
    updMsgs();
}


void MainWindow::on_newDialogButton_clicked()
{
    QString newName = ui->newDialogEdit->text();
    ui->newDialogEdit->clear();
    if(newName != ""){
        if(newName != currentUser.getName()){
            bool foundUser = false;
            for(int i = 0; i <userList.size(); i++){
                if(userList[i].getName() == newName)
                {
                    foundUser = true;
                    break;
                }
            }
            if(foundUser){
                bool foundDialog = false;
                for(int i = 0; i < curDialogs.size();i++){
                    if(dialogs[curDialogs[i]].getName1() == newName ||dialogs[curDialogs[i]].getName2() == newName){
                        foundDialog = true;
                        break;
                    }
                }
                if(!foundDialog){
                    dialogs.push_back(Dialog(currentUser.getName(),ui->newDialogEdit->text()));
                    updDialogs();
                }
            }
        }
    }
}

