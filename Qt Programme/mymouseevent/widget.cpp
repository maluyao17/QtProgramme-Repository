#include "widget.h"
#include "ui_widget.h"
#include<QMouseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //创建光标对象
    QCursor cursor;
    //设置光标形状
    cursor.setShape(Qt::OpenHandCursor);
    setCursor(cursor);
    //设置鼠标跟踪
    setMouseTracking(true);
}

//鼠标按下事件
void Widget::mousePressEvent(QMouseEvent *event)
{
    //如果是鼠标左键按下
    if(event->button()==Qt::LeftButton)
    {
        QCursor cursor;
        cursor.setShape(Qt::ClosedHandCursor);
        //使鼠标指针暂时改变形状
        QApplication::setOverrideCursor(cursor);
        //获取指针位置和窗口位置的差值
        offset=event->globalPos()-pos();
    }
    else if(event->button()==Qt::RightButton)
    {
      QCursor cursor(QPixmap("..."));
      QApplication::setOverrideCursor(cursor);
    }
}

//鼠标移动事件
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()&Qt::LeftButton)
    {
        QPoint temp;
        temp=event->globalPos()-offset;
        //窗口移动量=鼠标指针-当前位置
        move(temp);
    }
}

//鼠标释放事件
void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    //没有用到event参数
    Q_UNUSED(event);
    //恢复鼠标形状
    QApplication::restoreOverrideCursor();
}

//鼠标双击事件
void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        //如果现在不是全屏
        if(windowState()!=Qt::WindowFullScreen)
        {
            setWindowState(Qt::WindowFullScreen);
        }
        else
        {
            setWindowState(Qt::WindowNoState);
        }
    }
}

//滚轮事件
void Widget::wheelEvent(QWheelEvent *event)
{
    //当滚轮远离使用者时
    if(event->delta()>0)
    {
        //放大
        ui->textEdit->zoomIn();
    }
    else
    {
        ui->textEdit->zoomOut();
    }
}

Widget::~Widget()
{
    delete ui;
}
