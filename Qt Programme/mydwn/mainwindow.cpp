#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtWinExtras>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if(QtWin::isCompositionEnabled())
    {
        qDebug()<<"true";
        QtWin::extendFrameIntoClientArea(this,-1,-1,-1,-1);
        setAttribute(Qt::WA_TranslucentBackground,true);
        setAttribute(Qt::WA_NoSystemBackground,false);
        setStyleSheet("MainWindow{background:transparent;}");
    }
    else
    {
        qDebug()<<"false";
        QtWin::resetExtendedFrame(this);
        setAttribute(Qt::WA_TranslucentBackground,false);
        setStyleSheet(QString("MainWindow{background:%1;}").arg(QtWin::realColorizationColor().name()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
