#include "mywidget.h"
#include "ui_mywidget.h"
#include"mydialog.h"
#include<QDialog>
#include<QDebug>
#include<QColorDialog>
#include<QFileDialog>
#include<QFontDialog>
#include<QInputDialog>
#include<QMessageBox>
#include<QProgressDialog>
#include<QErrorMessage>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    //发射信号的对象，发射的信号，接收信号的对象，要是执行的槽
    connect(ui->showChildButton,&QPushButton::clicked,this,&MyWidget::showChildDialog);
    errordlg=new QErrorMessage(this);
}

void MyWidget::showChildDialog()
{
    QDialog *dialog=new QDialog(this);
    dialog->show();
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_pushButton_clicked()
{
    //隐藏主界面myWidget
    close();
    //新建MyDialog对象
    MyDialog dlg;
    if(dlg.exec()==QDialog::Accepted)
    {
        show();
    }
}

void MyWidget::on_pushButton_3_clicked()
{
    //创建对象
    QColorDialog dialog;
    //显示alpha
    dialog.setOption(QColorDialog::ShowAlphaChannel);
//    dialog.exec();
   //获取当前颜色
    QColor color = dialog.getColor();
    qDebug()<<"color:"<<color;
}

void MyWidget::on_pushButton_4_clicked()
{
    //参数：指定父窗口，设置对话框标题，指定默认打开的目标路径，设置文件类型的过滤器
    QString fileName=QFileDialog::getOpenFileName(this,tr("文件对话框"),"C:",tr("图片文件(*png *jpg);;文本文件(*txt)"));
    qDebug()<<"fileName:"<<fileName;
}

void MyWidget::on_pushButton_5_clicked()
{
    //bool值判断单击
    bool ok;
    //获取选择的字体
    QFont font=QFontDialog::getFont(&ok,this);
    if(ok==true)
    {
        ui->pushButton_5->setFont(font);
    }
    else
    {
        qDebug()<<tr("没有选择字体");
    }
}

void MyWidget::on_pushButton_6_clicked()
{
    bool ok;
    //获取字符串
    //指定父窗口，设置窗口标题，设置对话框中的标签显示文本，设置输入字符串的显示模式，设置输入框中的默认字符串，设置获取按下按钮信息的bool变量
    QString string=QInputDialog::getText(this,tr("输入字符串对话框"),tr("请输入用户名"),QLineEdit::Normal,tr("admin"),&ok);
    if(ok)
    {
        qDebug()<<"string:"<<string;
    }
    //获取整数
    int value1=QInputDialog::getInt(this,tr("输入整数对话框"),tr("请输入-1000到1000之间的数值"),100,-1000,1000,2,&ok);
    if(ok)
    {
        qDebug()<<"value1:"<<value1;
    }
    //获取浮点数
    int value2=QInputDialog::getDouble(this,tr("输入浮点数的对话框"),tr("请输入-1000到1000之间的数值"),0.00,-1000,1000,2,&ok);
    if(ok)
    {
        qDebug()<<"value2:"<<value2;
    }
    //获取条目
    QStringList items;
    items<<tr("条目1")<<("条目2");
    QString item=QInputDialog::getItem(this,tr("输入条目对话框"),tr("请输入或选择一个条目"),items,0,true,&ok);
    if(ok)
    {
        qDebug()<<"item:"<<item;
    }
}

void MyWidget::on_pushButton_7_clicked()
{
    //问题对话框
    int ret1=QMessageBox::question(this,tr("问题对话框"),tr("你了解Qt吗？"),QMessageBox::Yes,QMessageBox::No);
    if(ret1==QMessageBox::Yes)
    {
        qDebug()<<tr("问题！");
    }
    //提示对话框
    int ret2=QMessageBox::information(this,tr("提示对话框"),tr("这是Qt书籍！"),QMessageBox::Ok);
    if(ret2==QMessageBox::Ok)
    {
        qDebug()<<tr("提示！");
    }
    //警告对话框
    int ret3=QMessageBox::warning(this,tr("警告对话框"),tr("不能提前结束！"),QMessageBox::Abort);
    if(ret3==QMessageBox::Abort)
    {
        qDebug()<<tr("警告！");
    }
    //错误对话框
    int ret4=QMessageBox::critical(this,tr("严重错误对话框"),tr("发现了严重错误，需关闭所有文件"),QMessageBox::YesAll);
    if(ret4==QMessageBox::YesAll)
    {
        qDebug()<<tr("错误！");
    }
    //关于对话框
    QMessageBox::about(this,tr("关于对话框"),tr("guanyu"));
}

void MyWidget::on_pushButton_8_clicked()
{
    QProgressDialog dialog(tr("文件复制进度"),tr("取消"),0,50000,this);
    dialog.setWindowTitle(tr("进度对话框"));
    //设置模态对话框
    dialog.setWindowModality(Qt::WindowModal);
    dialog.show();
    for(int i=0;i<50000;i++)
    {
        //设置进度条当前值
        dialog.setValue(i);
        //避免界面冻结
        QCoreApplication::processEvents();
        //按下取消按钮中断
        if(dialog.wasCanceled())
        {
            break;
        }
    }
    //显示100%
    dialog.setValue(50000);
    qDebug()<<tr("复制结束!");
}

void MyWidget::on_pushButton_9_clicked()
{
   errordlg->setWindowTitle(tr("错误信息对话框"));
   errordlg->showMessage(tr("这里是出错信息！"));
}

QWizardPage * MyWidget::creatPage1()
{
    QWizardPage *page=new QWizardPage;
    page->setTitle(tr("介绍"));
    return page;
}

QWizardPage * MyWidget::creatPage2()
{
    QWizardPage *page=new QWizardPage;
    page->setTitle(tr("用户信息"));
    return page;
}

QWizardPage * MyWidget::creatPage3()
{
    QWizardPage *page=new QWizardPage;
    page->setTitle(tr("结束"));
    return page;
}

void MyWidget::on_pushButton_10_clicked()
{
    QWizard wizard(this);
    wizard.setWindowTitle(tr("向导对话框"));
    //添加向导页面
    wizard.addPage(creatPage1());
    wizard.addPage(creatPage2());
    wizard.addPage(creatPage3());
    wizard.exec();
}

