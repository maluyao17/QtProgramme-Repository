#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include"handler.h"
#include"handler2.h"
#include"myscene.h"
#include"times.h"
#include<QTimer>
 int num=1;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->sc=new myScene;
    this->ptimer2 =new QTimer(this);
    this->ui->graphicsView->setScene(sc);//交给显示

    connect(this->ui->btn_start,SIGNAL(clicked(bool)),this,SLOT(startTime()));
    connect(this->ptimer2,&QTimer::timeout,[=](){

            ui->label->setText(QString::number(num++));

    });
    connect(this->ui->btn_start,SIGNAL(clicked(bool)),this->sc,SLOT(startGame()));
    connect(this->ui->btn_start,SIGNAL(clicked(bool)),this,SLOT(startTime()));
    connect(this->ui->btn_pause,SIGNAL(clicked(bool)),this->sc,SLOT(pauseGame()));
    connect(this->ui->btn_pause,SIGNAL(clicked(bool)),this,SLOT(pauseTime()));
    connect(this->ui->btn_stop,SIGNAL(clicked(bool)),this->sc,SLOT(stopGame()));
    connect(this->ui->btn_stop,SIGNAL(clicked(bool)),this,SLOT(stopTime()));
    this->score=0;
    handler*hand=handler::getInstance();
    connect(hand,SIGNAL(beatMouse()),this,SLOT(UpdateScore()));//绑定槽函数
    handler2*hand2=handler2::getInstance2();
    connect(hand2,SIGNAL(unbeatMouse()),this,SLOT(UpdateScore2()));


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::closeEvent(QCloseEvent *event)
{
    int ret=QMessageBox::question(this,"确定","真的要走嘛嘤嘤嘤·  ","是","否");
    if(ret==1)
    {
        event->ignore();//点击否，忽略关闭的事件ignore忽略
    }
}
void MainWindow::UpdateScore()
{
    this->score+=10;
    this->cnt=0;
    this->ui->lcdNumber->display((this->score));
}
void MainWindow::UpdateScore2()
{
    this->score-=10;
    this->cnt++;
    if((this->cnt==3)||(this->score==-10))
    {
        myScene::stopp(*sc);
        this->score=0;
        this->stopTime();
        ui->label->setText(QString::number(0));

    }
    this->ui->lcdNumber->display((this->score));

}
void MainWindow::startTime()
{
    this->ptimer2->start(1500);
}
void MainWindow::pauseTime()
{

    this->ptimer2->stop();
}
void MainWindow::stopTime()
{

    this->ptimer2->stop();
    num=1;
    ui->label->setText(QString::number(0));
}
