#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <message.h>
#include <user.h>
#include <dialog.h>
#include <QListWidgetItem>
#include <QScrollBar>
#include <QFile>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QVector<User> userList,User user, QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_enterButton_clicked();

    void on_userList_itemClicked(QListWidgetItem *item);

    void on_newDialogButton_clicked();

private:
    void findCurUserDialogs();
    void updMsgs();
    void updDialogs();
    Ui::MainWindow *ui;
    User currentUser;
    QVector<User> userList;
    QVector <Dialog> dialogs;
    QVector <int> curDialogs;
    int curDialog;
};
#endif // MAINWINDOW_H
