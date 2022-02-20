#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>

class MyClass : public QObject
{
    Q_OBJECT

    //注册属性userName
    Q_PROPERTY(QString userName READ getUserName WRITE setUserName NOTIFY userNameChanged)
public:
    explicit MyClass(QObject *parent = nullptr);
    //实现READ读函数
    QString getUserName() const {return m_userName;}
    //实现WRITE写函数
    void setUserName(QString userName)
    {
        m_userName =userName;
        //属性改变时发射此信号
        emit userNameChanged(userName);
    }

signals:
    //声明NOTIFY通知消息
    void userNameChanged(QString);

private:
    //存放属性值
    QString m_userName;

public slots:
};

#endif // MYCLASS_H
