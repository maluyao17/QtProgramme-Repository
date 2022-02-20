#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui->pushButton->setStyleSheet("background:yellow");
//    ui->horizontalSlider->setStyleSheet("background:blue");
    setStyleSheet("QPushButton{background:yellow}QSlider{background:blue}");

    qssFile=new QFile(":/qss/my.qss",this);
    //只读的方式打开该文件
    qssFile->open(QFile::ReadOnly);
    //读取全部的内容
    QString stylesheet=QString(qssFile->readAll());
    qApp->setStyleSheet(stylesheet);
    qssFile->close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
