#ifndef MYSYNTAXHIGHLIGHTER_H
#define MYSYNTAXHIGHLIGHTER_H
#include<QSyntaxHighlighter>
#include<QString>


class MySyntaxHighlighter:public QSyntaxHighlighter
{
    Q_OBJECT
public:
    explicit MySyntaxHighlighter(QTextDocument *parent=0);
protected:
    void highlightBlock(const QString &text);

private:


};

#endif // MYSYNTAXHIGHLIGHTER_H
