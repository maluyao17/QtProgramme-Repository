#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //将监视器信号与自定义槽相关联
    connect(&myWatcher,&QFileSystemWatcher::directoryChanged,
            this,&MainWindow::showMessage);
    connect(&myWatcher,&QFileSystemWatcher::fileChanged,
            this,&MainWindow::showMessage);
    //显示当前目录下的所有.h文件
    QDir myDir(QDir::currentPath());
    myDir.setNameFilters(QStringList("*.h"));
    ui->listWidget->addItem(myDir.absolutePath()+tr("目录下的.h文件有:"));
    ui->listWidget->addItems((myDir.entryList()));
    //创建目录，并将其加入到监视器中
    QFile file(myDir.absolutePath()+"myfile.txt");
    if(file.open(QIODevice::WriteOnly))
    {
        QFileInfo info(file);
        ui->listWidget->addItem(tr("监视的文件:")+info.absoluteFilePath());
        myWatcher.addPath(info.absoluteFilePath());
        file.close();
    }
}

//显示文件或目录改变信息
void MainWindow::showMessage(const QString &path)
{
    QDir dir(QDir::currentPath()+"/mydir");
    //如果是目录发生了改变
    if(path==dir.absolutePath())
    {
        ui->listWidget->addItem(dir.dirName()+tr("目录发生改变:"));
        ui->listWidget->addItems(dir.entryList());
    }
    else
    {
        //如果文件发生了改变
        ui->listWidget->addItem(path+tr("文件发生改变!"));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
