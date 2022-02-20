#include "dialogaction.h"
#include<QLineEdit>
#include<QSplitter>
#include<QLabel>
#include<QDialog>
#include<QString>
#include<QCompleter>

dialogaction::dialogaction(QObject * parent):
    QWidgetAction(parent)
{
    //创建行编辑器
    lineEdit=new QLineEdit;
    lineEdit->resize(2000,2000);
    //将行编辑器的按下回车键信号与发送文本槽关联
    connect(lineEdit,&QLineEdit::returnPressed,this,&dialogaction::sendText);

    //自动补全
    QStringList wordList1;
    wordList1<<"Con"<<"Conv2D"<<"Data"<<"Dataset"<<"DataLoader"<<"Mod"<<"Module";
    //新建自动补全器
    QCompleter *completer=new QCompleter(wordList1,this);
    //设置大小写不敏感
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    lineEdit->setCompleter(completer);


}

QWidget*dialogaction::createdWidget(QWidget * parent)
{
    //判断父部件是否为菜单或者工具栏
    //是，创建子部件，返回子部件
    //不是，直接返回0
        QSplitter *splitter=new QSplitter(parent);
        splitter->resize(705,20);
        splitter->addWidget(lineEdit);
        splitter->move(400,0);
        return splitter;

}
void dialogaction::sendText()
{
    //发射信号，将行编辑器中的内容发射出去
    emit getText(lineEdit->text());
    //清空行编辑器里的内容
    lineEdit->clear();
}
