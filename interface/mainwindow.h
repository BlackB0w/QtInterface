#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QResizeEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void resizeEvent(QResizeEvent *e);
private slots:

    void on_amplifierDial_valueChanged(int value);

    void on_volumeDial_valueChanged(int value);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    int getSignal();
};
#endif // MAINWINDOW_H
