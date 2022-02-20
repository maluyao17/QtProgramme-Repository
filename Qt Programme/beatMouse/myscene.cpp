#include "mainwindow.h"
#include<stdlib.h>
#include<QTimer>
#include "myscene.h"
#include"ui_mainwindow.h"
#include<QMessageBox>
extern int num;
myScene::myScene(QObject *parent) : QGraphicsScene(parent)
{
//    this->item=new myItem;
//    //设置位置
//    this->item->setPos(0,0);
//    this->addItem(this->item);

//    myItem * item2=new myItem;
//    this->addItem(this->item2);//形成重叠，需指定位置
//    myItem * item2=new myItem;
//    item2->setPos(325,0);
//    this->addItem(item2);

    int i=0;
    for(i=0;i<16;i++)
    {
        this->item[i]=new myItem;
        //直接获取尺寸
        this->item[i]->setPos(i/4*this->item[i]->boundingRect().width(),i%4*this->item[i]->boundingRect().height());
        this->addItem(this->item[i]);
    }
    this->ptimer =new QTimer(this);//计时器
    connect(this->ptimer,SIGNAL(timeout()),this,SLOT(showMouse()));
    //绑定信号与槽
    //this->ptimer->start(700);
//    connect(this->ptimer,&QTimer::timeout,[=](){
//            static int num=1;
//            MainWindow.ui->label->setText(QString::number(num++));

//    });
}
 void myScene::showMouse()
 {
      static int x=2;
      if(num%5==0)
      {
          x++;
      }
      int count = rand()%x+1;
      int i=0;
      //每次循环开始前重置
      for(i=0;i<16;i++)
      {
          this->item[i]->setPic(":/bg/png/didong_copy.png");
          this->item[i]->setMouse(false);
      }
      for(i=0;i<count;i++)
      {
          int index=rand()%16;
          this->item[index]->setPic(":/bg/png/mouse.png");
          this->item[index]->setMouse(true);
      }

 }
void myScene::startGame()
{

    int i=0;
    for(i=0;i<16;i++)
    {
        this->item[i]->setStart((true));
    }
    this->ptimer->start(1500);
}
void myScene::pauseGame()
{

    int i=0;
    for(i=0;i<16;i++)
    {
        this->item[i]->setStart((false));
    }
    this->ptimer->stop();
}
void myScene::stopGame()
{
    int i=0;
    for(i=0;i<16;i++)
    {
        this->item[i]->setStart((false));
    }
    this->ptimer->stop();
    //对界面初始化
    for(i=0;i<16;i++)
    {
        this->item[i]->setPic(":/bg/png/didong_copy.png");
        this->item[i]->setMouse(false);
    }
}
void myScene::stopp(myScene&s)
{
    s.ptimer->stop();
    int i;
    for(i=0;i<16;i++)
    {
        s.item[i]->setPic(":/bg/png/didong_copy.png");
        s.item[i]->setMouse(false);
    }
}
