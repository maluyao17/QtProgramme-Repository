#include "widget.h"
#include "ui_widget.h"
#include<QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //Qt5模式字符串
    QRegularExpression re("a pattern");
    //Qt5用setPattern()
    QRegularExpression re2;
    re2.setPattern("Another Pattern");
    //不区分大小写
    QRegularExpression re3("Qt rocks",QRegularExpression::CaseInsensitiveOption);
    //通过patternOption()
    QRegularExpression re4("^\\d+$");
    re4.setPatternOptions(QRegularExpression::MultilineOption);
    //设置^匹配开头，$匹配结尾
    QRegularExpression::PatternOptions option =re.patternOptions();

    QRegularExpression re5("^(\\d\\d)/(\\d\\d)/(\\d\\d\\d\\d)$");
    QRegularExpressionMatch match=re5.match("08/12/1985");
    if(match.hasMatch())
    {
        QString matched=match.captured(0);
        QString day=match.captured(1);
        QString month=match.captured(2);
        QString year=match.captured(3);
        qDebug()<<"match:"<<match
               <<"day:"<<day
              <<"month:"<<month
             <<"year:"<<year;
    }

    QString pattern("^(Jan|Feb|Mar|Apr|May) \\d\\d?,\\d\\d\\d$");
    QRegularExpression re6(pattern);
    QString input("Jan 21,");
    QRegularExpressionMatch match1=re6.match(input,0,QRegularExpression::PartialPreferCompleteMatch);
    //判断完全匹配
    bool hasMatch=match1.hasMatch();
    //判断部分匹配
    bool hasParticalMatch=match1.hasPartialMatch();
    qDebug()<<"match:"<<hasMatch<<"ParticalMatch:"<<hasParticalMatch;

    QRegularExpression re7("\\d\\d\\w+");
    //跳过第一个匹配到的12 abc 偏移量为1
    QRegularExpressionMatch match2=re.match("12 abc 45 def",1);
}

Widget::~Widget()
{
    delete ui;
}
