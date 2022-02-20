#include "widget.h"
#include "ui_widget.h"
#include<QKeyEvent>
#include<QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //使主界面获得焦点
    setFocus();

    keyUp=false;
    keyLeft=false;
    move=false;
}

//键盘按下事件
void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Up)
    {
        if(event->isAutoRepeat())
        {
            return ;
        }
        keyUp=true;
    }
    else if(event->key()==Qt::Key_Left)
    {
        if(event->isAutoRepeat())
        {
            return;
        }
        keyLeft=true;
    }

}

//按键释放事件
void Widget::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Up)
    {
        if(event->isAutoRepeat())
        {
            return ;
        }
        keyUp=false;
        if(move)
        {
            //如果完成了移动设为false
            move=false;
            return;
        }
        //如果向左方向键已经按下且没有释放
        if(keyLeft)
        {
            ui->pushButton->move(30,80);
            move=true;
        }
        else
        {
            ui->pushButton->move(120,80);
        }
    }
    else if(event->key()==Qt::Key_Left)
    {
            if(event->isAutoRepeat())
            {
                return ;
            }
            keyLeft=false;
            if(move)
            {
                //如果完成了移动设为false
                move=false;
                return;
            }
            if(keyUp)
            {
                ui->pushButton->move(30,80);
                move=true;
            }
            else
            {
                ui->pushButton->move(30,120);
            }

    }
    else if(event->key()==Qt::Key_Down)
    {
        ui->pushButton->move(120,120);
    }


}

Widget::~Widget()
{
    delete ui;
}
