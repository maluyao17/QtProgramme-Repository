#include "widget.h"
#include "ui_widget.h"
#include "mybutton.h"
#include<QPushButton>
#include<QDebug>
#include<QHBoxLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //创建按钮部件 指定widget为父部件
    MyButton *button=new MyButton(this);
    button->setText(tr("mybutton"));
    MyButton *button2=new MyButton;
    MyButton *button3=new MyButton;
    QHBoxLayout *layout=new QHBoxLayout;
    layout->addWidget(button2);
    layout->addWidget(button3);
    //使用布局管理器后button会调用自己的父物体进行销毁
    setLayout(layout);
    qDebug()<<children();
}

Widget::~Widget()
{
    delete ui;
    qDebug()<<"delete widget";
}
