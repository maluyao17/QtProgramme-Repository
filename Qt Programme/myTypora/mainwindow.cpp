#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTextFrame>
#include<QTextCursor>
#include<QLabel>
#include<QString>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //获取文档对象
    QTextDocument *document=ui->textEdit->document();
    //获取根框架
    QTextFrame *rootframe=document->rootFrame();
    //创建框架格式
    QTextFrameFormat format;
    //边界颜色
    format.setBorderBrush(Qt::white);
    //边界宽度
    format.setBorder(1);
    //框架使用格式
    rootframe->setFrameFormat(format);

    //状态栏
    ui->statusBar->showMessage(tr("myTypora 1.0.0"),2000);
    permanet =new QLabel(this);
    permanet->setFrameStyle(QFrame::Box||QFrame::Sunken);
    ui->statusBar->addPermanentWidget(permanet);
}

void MainWindow::on_textEdit_textChanged()
{
    qDebug("get");
    QTextCursor tc = ui->textEdit->textCursor(); //当前光标
    int rowNum = tc.blockNumber() + 1;//获取光标所在行的行号
    permanet->setText(QString::number(rowNum));
}

MainWindow::~MainWindow()
{
    delete ui;
}
