#include "widget.h"
#include "ui_widget.h"
#include<QKeyEvent>
#include<QWheelEvent>
#include<QKeyEvent>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //在编辑器上安装事件过滤器
    ui->textEdit->installEventFilter(this);
    ui->spinBox->installEventFilter(this);
    //创建键盘事件
    QKeyEvent myEvent(QEvent::KeyPress,Qt::Key_Up,Qt::NoModifier);
    //发送键盘事件到SpinBox
    qApp->sendEvent(ui->spinBox,&myEvent);
}

bool Widget::eventFilter(QObject *obj, QEvent *event)
{
    if(obj==ui->textEdit)
    {
        if(event->type()==QEvent::Wheel)
        {
            //强制转换事件类型
            QWheelEvent *wheelEvent=static_cast <QWheelEvent*>(event);
            if(wheelEvent->delta()>0)
            {
                ui->textEdit->zoomIn();
            }
            else
            {
                ui->textEdit->zoomOut();
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(obj==ui->spinBox)
    {
        if(event->type()==QEvent::KeyPress)
        {
            QKeyEvent *keyEvent=static_cast<QKeyEvent*>(event);
            if(keyEvent->key()==Qt::Key_Space)
            {
                ui->spinBox->setValue(0);
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        return eventFilter(obj,event);
    }
}

Widget::~Widget()
{
    delete ui;
}
