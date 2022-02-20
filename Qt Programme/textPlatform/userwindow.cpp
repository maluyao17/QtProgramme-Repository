#include "userwindow.h"
#include "ui_userwindow.h"
#include"cmdwindow.h"
#include<QDragEnterEvent>
#include<QUrl>
#include<QFile>
#include<QTextStream>
#include<QMimeData>
#include<QSettings>
#include <QApplication>
#include <QDir>
#include<QString>
#include<qDebug>
#include<QFileDialog>
#include<QTextStream>
#include<QLCDNumber>
#include<QColorDialog>
#include<QInputDialog>
#include<QTime>

UserWindow::UserWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("UserWindow");
    ui->textEdit->setPlainText("test");
    //查找
    file_ini = new QSettings("..//CONFIG2.ini",QSettings::IniFormat);
    IO_ini = new QSettings("..//CONFIG2.ini",QSettings::IniFormat);
    score_ini=new QSettings("..//CONFIG3.ini",QSettings::IniFormat);
    time_ini=new QSettings("..//CONFIG3.ini",QSettings::IniFormat);
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);
}

UserWindow::~UserWindow()
{
    delete ui;
}

void UserWindow::dragEnterEvent(QDragEnterEvent *event)
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

void UserWindow::dropEvent(QDropEvent *event)
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
            ui->textEdit->setPlainText(in.readAll());
        }
    }
}

void UserWindow::on_pushButton_3_clicked()
{
 //   QApplication a(argc, argv);
    int file_num=0;

    //    MainWindow w;
    //    w.show();
    QDir dir(ui->textEdit->toPlainText());//如果不加地址，则就在当前目录下遍历
    QStringList filters;
    file=file_ini->value(ui->lineEdit->text()
                         ).toString();
    filters << file;//设置过滤类型
    qDebug()<<file;
    dir.setNameFilters(filters);//设置文件名的过滤
    QFileInfoList list = dir.entryInfoList();
    if(list.length()!=0)
        for (int i = 0; i < list.size(); ++i)
        {
            ui->textEdit->setPlainText(list.at(i).fileName().arg((QString)file_num));
            file_num++;
            score=+5;
            ui->lcdNumber->display(score);

        }
    else
    {
        ui->textEdit->setPlainText("no file");
    }
    QString s = QString("%1").arg(file_num);
    ui->textEdit->append(s);
    qDebug()<<file_num;
 //   return a.exec();
}

void UserWindow::on_pushButton_4_clicked()
{
    IO=IO_ini->value(ui->lineEdit_2->text()).toString();
    qDebug()<<IO;
    int IO_num=0;
    QString string = ui->lineEdit_2->text();
    bool isfind=ui->textEdit_2->find(IO,QTextDocument::FindBackward);
    qDebug()<<ui->textEdit_2->toPlainText();
    while(isfind)
    {
        isfind=ui->textEdit_2->find(IO,QTextDocument::FindBackward);
        IO_num++;
        score+=3;
        ui->lcdNumber->display(score);
        qDebug()<<IO_num;
    }
    ui->textEdit_2->setPlainText(IO);
    QString s = QString("%1").arg(IO_num);
    ui->textEdit_2->append(s);
}

void UserWindow::on_actionOpen_O_triggered()
{
    auto filePath
        = QFileDialog::getOpenFileName(this,
                                       "Open text",
                                       QString(),
                                       "Text files (*.txt);;All files (*)");//打开文件

    if (!filePath.isEmpty()) {
        QFile f(filePath);//读取文件路径
        if (!f.open(QIODevice::ReadOnly | QIODevice::Text))//只读，行结束符转化为/n
            return;
        QTextStream in(&f);
        QString str(in.readAll());
        ui->textEdit_2->setPlainText(str);//读取所有数据，隐式转化为QString
        f.close();//关闭文件对象
        _filePath = filePath;
    }

}

void UserWindow::on_pushButton_clicked()
{
    ui->lineEdit->clear();
}

void UserWindow::on_pushButton_2_clicked()
{
    ui->textEdit->clear();
}


void UserWindow::on_pushButton_5_clicked()
{
    ui->lineEdit_2->clear();
}

void UserWindow::on_pushButton_6_clicked()
{
    ui->textEdit_2->clear();
}

void UserWindow::on_actionLcdColor_L_triggered()
{
    QColorDialog dialog;
    dialog.setOption(QColorDialog::ShowAlphaChannel);
    dialog.exec();
    QColor color=dialog.currentColor();
    //计时器ui
    QPalette lcdpat=ui->lcdNumber->palette();
    lcdpat.setColor(QPalette::Normal,QPalette::WindowText,color);
    ui->lcdNumber->setPalette(lcdpat);
}

void UserWindow::on_actionSave_Score_S_triggered()
{
    QDateTime dateTime(QDateTime::currentDateTime());
    QString qStr = dateTime.toString("yyyy-MM-dd hh:mm:ss");

    QString string=QInputDialog::getText(this,tr("Save Score:"),tr("Data Name:"));
    QString time=string+"time";
    double saveSocre=ui->lcdNumber->value();
    QVariant s(saveSocre);
    QVariant t=qStr;
    score_ini->setValue(string,s);
    time_ini->setValue(time,t);
}
