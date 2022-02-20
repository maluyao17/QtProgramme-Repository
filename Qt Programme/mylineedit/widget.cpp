#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QString>
#include<QCompleter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //新建验证器
    QValidator *validator=new QIntValidator(100,999,this);
    ui->lineEdit_3->setValidator(validator);
    //自动补全
    QStringList wordList;
    wordList<<"Qt"<<"Qt Creater"<<tr("你好");
    //新建自动补全器
    QCompleter *completer=new QCompleter(wordList,this);
    //设置大小写不敏感
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit_4->setCompleter(completer);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_lineEdit_2_returnPressed()
{
    //让lineEdit3获得焦点
    ui->label_3->setFocus();
    qDebug()<<ui->lineEdit_2->text();
    qDebug()<<ui->lineEdit_2->displayText();
}
