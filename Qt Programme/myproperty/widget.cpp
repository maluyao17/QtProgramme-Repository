#include "widget.h"
#include "ui_widget.h"
#include"myclass.h"
#include<QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //创建MyClass类实例
    MyClass *my=new MyClass(this);
    connect(my,&MyClass::userNameChanged,this,&Widget::userChanged);
    //设置属性值
    my->setUserName("abc");
    qDebug()<<"userName1:"<<my->getUserName();

    //使用QOBJECT类设置属性值
    my->setProperty("userName","Linux");
    //返回值为QVariant
    qDebug()<<"userName2:"<<my->property("userName:").toString();

    my->setProperty("myValue",10);
    qDebug()<<"myValue:"<<my->property("myValue").toInt();
}

void Widget::userChanged(QString userName)
{
    qDebug()<<"user changed:"<<userName;
}

Widget::~Widget()
{
    delete ui;
}
