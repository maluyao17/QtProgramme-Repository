#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QTimer>
#include<QTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    id1=startTimer(1000);
    id2=startTimer(1500);
    id3=startTimer(2200);

    lcd=new QLCDNumber(this);
    lcd->resize(200,200);
    lcd->show();
    QTimer *timer=new QTimer(this);
    //关联到定时器的溢出信号到槽上
    connect(timer,&QTimer::timeout,this,&Widget::timeUpdate);
    timer->start(1000);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    QTimer::singleShot(10000,this,&Widget::close);
}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==id1)
    {
        qDebug()<<"time1";
    }
    else if(event->timerId()==id2)
    {
        qDebug()<<"time2";
    }
    else if(event->timerId()==id3)
    {
        qDebug()<<"time3";
    }
}

void Widget::timeUpdate()
{

    QTime time = QTime::currentTime();
    QString text =time .toString("hh:mm");
    if(time.second()%2==0)
    {
        text[2]=' ';
    }
    this->lcd->display(text);
    int rand=qrand()%300;
    this->lcd->move(rand,rand);
}

Widget::~Widget()
{
    delete ui;
}
