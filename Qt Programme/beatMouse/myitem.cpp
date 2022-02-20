#include "myitem.h"
#include<QPixmap>
#include<QDebug>
#include"handler.h"
#include"handler2.h"
#include<QCursor>
#include"myscene.h"
myItem::myItem()
{
    this->setCursor(QCursor(QPixmap(":/mouse/png/hit.png")));
    this->setPixmap(QPixmap(":/bg/png/didong_copy.png"));//格式转换
    this->start=false;
    this->Mouse=false;
}

void myItem::setPic(QString path)
{
    this->setPixmap(QPixmap(QPixmap(path)));
}
//
void myItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(QPixmap(":/mouse/png/hit.png")));
    if(this->isStart())
    {
        handler*hand=handler::getInstance();
        handler2*hand2=handler2::getInstance2();
        if(this->isMouse())
        {
            hand->addScore();//发送信号
            this->setCursor(QCursor(QPixmap(":/mouse/png/mousehit.png")));
            this->Mouse=false;
        }
        else
        {
            hand2->DecreaseScore();

            qDebug()<<"打得不是老鼠";
        }
    }
}
void myItem::setMouse(bool mouse)
{
    this->Mouse=mouse;
}
bool myItem::isMouse()
{
    return this->Mouse;
}
void myItem::setStart(bool start)
{
    this->start=start;
}
bool myItem::isStart()
{
    return this->start;
}
void myItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(QPixmap(":/mouse/png/hitdown.png")));
}
