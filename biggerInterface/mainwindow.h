#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <message.h>
#include <user.h>
#include <dialog.h>
#include <QListWidgetItem>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(User user, QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_enterButton_clicked();

    void on_userList_itemClicked(QListWidgetItem *item);

private:
    void findCurUserDialogs();
    void updMsgs();
    Ui::MainWindow *ui;
    User currentUser;
    QVector <Dialog> dialogs;
    QVector <int> curDialogs;
    int curDialog;
};
#endif // MAINWINDOW_H
