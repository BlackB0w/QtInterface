#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->draw->setCol(QColor(120,0,255));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *e)
{

}


void MainWindow::on_amplifierDial_valueChanged(int value)
{
    ui->amplifier->setValue(value);
}


void MainWindow::on_volumeDial_valueChanged(int value)
{
    ui->volume->setValue(value);
}


void MainWindow::on_pushButton_clicked()
{
    QVector<QVector<int>>pic;
    for(int i = 0;i<this->size().width();i++){
        pic.push_back(QVector<int>({i,getSignal()}));
        ui->draw->setPic(pic);
    }
}

int MainWindow::getSignal()
{
    return rand() %100 * ui->volumeDial->value()/100 + ui->amplifierDial->value();
}

