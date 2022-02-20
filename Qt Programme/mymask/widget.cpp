#include "widget.h"
#include "ui_widget.h"
#include<QPixmap>
#include<QBitmap>
#include<QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

//    QPixmap pixmap(":/image/image1.jpg");
//    ui->label->setPixmap(pixmap);
//    ui->label->setMask(pixmap.mask());

    QPixmap pix;
    //加载图片
    pix.load(":/image/image1.jpg");
    //设置窗口大小为图片大小
    resize(pix.size());
    setMask(pix.mask());
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,QPixmap(":/image/image1.jpg"));
}

void Widget::mousePressEvent(QMouseEvent *)
{
    close();
}

Widget::~Widget()
{
    delete ui;
}
