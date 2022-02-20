#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>
//单例类
class handler : public QObject
{
    Q_OBJECT
public:
    //静态函数，只能操作静态变量
    static handler*getInstance();
    void addScore();//向外发送信号
private:
    //构造函数设为私有，类外无法新建类的对象
    explicit handler(QObject *parent = nullptr);

signals:
    void beatMouse();//只需要写声明，就可以定义该信号
public slots:

private:
    static handler*hand; //静态成员变量，只能产生该实例
};

#endif // HANDLER_H
