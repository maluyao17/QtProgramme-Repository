#include "mydialog.h"
#include "ui_mydialog.h"

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::on_pushButton_clicked()
{
    accept();//QDialog类中的一个槽，隐藏模态对话框
}

void MyDialog::on_pushButton_3_clicked()
{
    //获取输入的数值
    int value=ui->spinBox->value();
    //发射信号
    emit dlgReturn(value);
    //关闭对话框
    close();
}
