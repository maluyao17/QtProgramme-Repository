#include "widget.h"
#include "ui_widget.h"
#include"mylineedit.h"
#include<QKeyEvent>
#include<QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    lineEdit=new MyLineEdit(this);
    lineEdit->move(100,100);
    //为lineEdit安装事件过滤器
    lineEdit->installEventFilter(this);
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<tr("Widget键盘按下事件");
}

//事件过滤器
bool Widget::eventFilter(QObject *obj, QEvent *event)
{
    if(obj==lineEdit)
    {
        if(event->type()==QEvent::KeyPress)
        {
            qDebug()<<tr("Widget的事件过滤器");
        }
    }
    return QWidget::eventFilter(obj,event);
}

Widget::~Widget()
{
    delete ui;
}
