#include "widget.h"
#include "ui_widget.h"
#include<QHBoxLayout>
#include<QGridLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //新建栅格布局
    QGridLayout *layout=new QGridLayout;
    //从0行0列开始，占据1行2列
    layout->addWidget(ui->fontComboBox,0,0,1,2);
    layout->addWidget(ui->pushButton,0,2,1,1);
    layout->addWidget(ui->textEdit,1,0,1,3);
    ui->textEdit->hide();
    setLayout(layout);
    setTabOrder(ui->lineEdit,ui->spinBox);
    setTabOrder(ui->spinBox,ui->pushButton);
    setTabOrder(ui->pushButton,ui->checkBox);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_toggled(bool checked)
{
    //设置文本编辑器显示与隐藏
    ui->textEdit->setVisible(checked);
    if(checked)
    {
        ui->pushButton->setText(tr("隐藏可拓展窗口"));
    }
    else
    {
        ui->pushButton->setText(tr("显示可拓展窗口"));
    }
}
