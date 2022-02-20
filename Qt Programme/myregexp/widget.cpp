#include "widget.h"
#include "ui_widget.h"
#include<QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //两个字符都必须为数字，第二个字符可以没有
    //0~99
    QRegExp rx("^\\d\\d? $");
    qDebug()<<rx.indexIn("a1");
    qDebug()<<rx.indexIn("5");
    qDebug()<<rx.indexIn("5x");
    qDebug()<<rx.indexIn("12");
    qDebug()<<rx.indexIn("123");
    qDebug()<<"******************";
    //匹配mail或者letter单词
    rx.setPattern("\\b(mail|letter)\\b");
    qDebug()<<rx.indexIn("emailletter");
    qDebug()<<rx.indexIn("my mail");
    qDebug()<<rx.indexIn("my mail letter");
    qDebug()<<"*******************";
    //匹配字符M，其后面不能跟有ail字符
    rx.setPattern("M(?!ail)");
    QString str1="this is M";
    str1.replace(rx,"Mail");
    qDebug()<<"str1:"<<str1;
    QString str2="my M,Your Ms,his Mail";
    str2.replace(rx,"Mail");
    qDebug()<<"str2:"<<str2;
    qDebug()<<"********************";
    QString str3="One Eric another Eirik."
            "and an Ericsson How many Ericks, Eric?";
    //E开头i可有可无，后接ri或rick，匹配数量
    QRegExp rx2("\\bEi?ri[ck]\\b");
    int pos=0;
    int count=0;
    while(pos>=0)
    {
        pos=rx2.indexIn(str3,pos);
        if(pos>=0)
        {
            ++pos;
            ++count;
        }
    }
    qDebug()<<"count:"<<count;

    QRegExp rx3("*.txt");
    rx3.setPatternSyntax(QRegExp::Wildcard);
    qDebug()<<rx3.exactMatch("README.txt");
    qDebug()<<rx3.exactMatch("Welcome.txt.bak");

    QRegExp rx4("(\\d+)");
    QString str4="Offsets:12 14 99 231 7";
    QStringList list;
    int pos2=0;
    while(pos2=rx4.indexIn(str4,pos2)!=-1)
    {
        //第一个捕获到的文本
        list<<rx4.cap(1);
        //上一个匹配的字符串的长度
        pos2+=rx4.matchedLength();
    }
    qDebug()<<list;
    QRegExp rxlen("(\\d+)(?:\\s*)(cm|inch)");
    int pos3=rxlen.indexIn("Length:189cm");
    if(po3>-1)
    {
        QString value=rxlen.cap(1);
        QString unit=rxlen.cap(2);
        QString string=rxlen.cap(3);
        qDebug()<<value<<unit<<string;
    }
    QRegExp rx5("\\b(\\w+)\\W+\\1\\b");
    //设置不区分大小写
    rx5.setCaseSensitivity(Qt::CaseInsensitive);
    qDebug()<<rx5.indexIn("Hello--hello");
    qDebug()<<rx5.cap(1);
    //匹配中文
    QRegExp rx6("\\你好\\");
    qDebug()<<rx6.indexIn("你好");
    //完全匹配使用0捕获
    qDebug()<<rx6.cap(0);

    //Qt5模式字符串
    QRegularExpression re("a pattern");
    //Qt5用setPattern()
    QRegularExpression re2;
    re2.setPattern("Another Pattern");
    //不区分大小写
    QRegularExpression re3("Qt rocks",QRegularExpression::CaseInsensitiveOption);

}

Widget::~Widget()
{
    delete ui;
}
