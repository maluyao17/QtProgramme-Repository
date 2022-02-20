#include "mywidget.h"
#include "ui_mywidget.h"
#include<QFont>
#include<QMenu>
#include<QDebug>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    QFont font;
    font.setFamily("华文行楷");
    font.setPointSize(20);
    font.setBold(true);
    font.setItalic(true);
    ui->label->setFont(font);

    QString string =tr("标题太长，需要进行忽略！");
    //文本忽略，参数：要省略的文本，省略模式，文本的长度
    QString str=ui->label->fontMetrics().elidedText(string,Qt::ElideRight,180);
    ui->label->setText(str);
    ui->pushButton->setText(tr("&nihao"));
    ui->pushButton_2->setText(tr("帮助(&H)"));
    ui->pushButton_3->setText("z&oom");
    QMenu *menu=new QMenu(this);
    ui->pushButton_3->setMenu(menu);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_pushButton_toggled(bool checked)
{
    //按钮是否处于被按下状态
    qDebug()<<tr("按钮是否按下：")<<checked;
}
