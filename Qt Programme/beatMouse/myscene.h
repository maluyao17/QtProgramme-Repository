#ifndef MYSCENCE_H
#define MYSCENCE_H

#include <QObject>
#include<QGraphicsScene>
#include<QTimer>
#include"myitem.h"

class myScene : public QGraphicsScene
{
    Q_OBJECT//信号与槽的宏定义
public:
    explicit myScene(QObject *parent = nullptr);
    static void stopp(myScene&s);

signals:

public slots:
    void showMouse();
    //公开槽函数
    void startGame();
    void pauseGame();
    void stopGame();
private:
    myItem*item[16];//利用一维数组布局二维矩阵
    QTimer* ptimer;

};

#endif // MYSCENCE_H
