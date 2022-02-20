#include <QCoreApplication>
#include<QList>
#include<QListIterator>
#include<QMutableListIterator>
#include<QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<QString> list;
    list<<"A"<<"B"<<"C"<<"D";
    //创建列表的只读迭代器，将list作为参数
    QListIterator<QString> i(list);
    qDebug()<<"the forwardis:";
    //正向遍历
    while(i.hasNext())
    {
        qDebug()<<i.next();
    }

    qDebug()<<"the backwardis:";
    //反向遍历
    while(i.hasPrevious())
    {
        qDebug()<<i.previous();
    }

    QMutableListIterator<QString> j(list);
    //返回列表尾部
    j.toBack();
    while(j.hasPrevious())
    {
        QString str=j.previous();
        //删除项目"B"
        if(str=="B")
        {
            j.remove();
        }
    }
    //在列表最前面项目添加"Q"
    j.insert("Q");
    j.toBack();
    if(j.hasPrevious())
    {
        j.previous()="N";
    }
    //取N的前一个，改变成M
    j.previous();
    j.setValue("M");
    j.toFront();
    qDebug()<<"the forward is:";
    while(j.hasNext())
    {
        qDebug()<<j.next();
    }

    return a.exec();
}
