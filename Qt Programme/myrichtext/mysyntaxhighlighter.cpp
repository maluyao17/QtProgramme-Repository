#include "mysyntaxhighlighter.h"
#include<QTextEdit>

MySyntaxHighlighter::MySyntaxHighlighter(QTextDocument *parent)
    :QSyntaxHighlighter(parent)
{
}
void MySyntaxHighlighter::highlightBlock(const QString &text)
{
    //字符格式
    QTextCharFormat myFormat;
    myFormat.setFontWeight(QFont::Bold);
    myFormat.setForeground(Qt::green);
    QString pattern="\\bchar\\b";
    //创建正则表达式类
    QRegExp expression(pattern);
    //从位置0开始匹配字符串
    int index=text.indexOf(expression);
    while (index>=0)
    {
        //获取所匹配字符串的长度
        int length=expression.matchedLength();
        //设置字符串格式
        setFormat(index,length,myFormat);
        //继续匹配
        index=text.indexOf(expression,index+length);
    }
}
