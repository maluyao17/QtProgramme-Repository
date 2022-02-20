#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    //创建按钮
    QPushButton *button =new QPushButton(this);
    //指定按钮对象名
    button->setObjectName("myButton");

    ui->setupUi(this);
}

void Widget::on_myButton_clicked()
{
    close();
}

Widget::~Widget()
{
    delete ui;
}
