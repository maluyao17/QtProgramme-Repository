#ifndef MYITEM_H
#define MYITEM_H
#include<QGraphicsPixmapItem>
#include<QString>
#include<QGraphicsSceneMouseEvent>
class myItem : public QGraphicsPixmapItem
{
public:
    myItem();
    void setPic(QString path);//更换图片，公开函数用于传入图元路径
    void mousePressEvent(QGraphicsSceneMouseEvent*event);//重写鼠标按下的事件
    void setMouse(bool Mouse);
    bool isMouse();
    void setStart(bool start);
    bool isStart();
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
    bool Mouse;
    //点击开始时是真
    bool start;
};

#endif // MYITEM_H
