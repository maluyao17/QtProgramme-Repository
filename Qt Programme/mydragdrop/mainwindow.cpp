#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDragEnterEvent>
#include<QUrl>
#include<QFile>
#include<QTextStream>
#include<QMimeData>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    //数据中是否包含URL
    if(event->mimeData()->hasUrls())
    {
        //如果是则接收动作
        event->acceptProposedAction();
    }
    else
    {
        //否则忽略该事件
        event->ignore();
    }
}

void MainWindow::dropEvent(QDropEvent *event)
{
    //获取MIME数据
    const QMimeData *mimeData=event->mimeData();
    //如果数据中包含URL
    if(mimeData->hasUrls())
    {
        //获取URL列表
        QList<QUrl>urlist=mimeData->urls();
        //将第一个URL表示为本地文件路径
        QString fileName=urlist.at(0).toLocalFile();
        //如果文件路径不为空
        if(!fileName.isEmpty())
        {
            //建立QFile对象并且以只读方式打开该文件
            QFile file(fileName);
            if(!file.open(QIODevice::ReadOnly))
                return;
            //建立文本流对象
            QTextStream in(&file);
            //将文件中所有内容读入编辑器
            ui->textEdit->setText(in.readAll());
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
