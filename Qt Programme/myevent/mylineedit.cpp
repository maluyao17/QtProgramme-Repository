#include "mylineedit.h"
#include<QKeyEvent>
#include<QDebug>

MyLineEdit::MyLineEdit(QWidget*parent):
  QLineEdit(parent)
{

}

void MyLineEdit::keyPressEvent(QKeyEvent *event)
{

    qDebug()<<tr("MyLineEdit键盘按下事件");
    //执行QLineEdit类的默认事件处理
    QLineEdit::keyPressEvent(event);
    event->ignore();
}

bool MyLineEdit::event(QEvent *event)
{
    if(event->type()==QEvent::KeyPress)
    {
        qDebug()<<tr("MyLineEdit的event()函数");
    }
    //执行父类默认操作
    return QLineEdit::event(event);
}
