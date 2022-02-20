#include "handler2.h"

handler2::handler2(QObject *parent) : QObject(parent)
{

}
handler2* handler2::hand2 =new handler2;
handler2* handler2::getInstance2()
{
    return hand2;
}
void handler2::DecreaseScore()
{
    emit unbeatMouse();//函数被调用时，就会发出beatmouse的信号
}
