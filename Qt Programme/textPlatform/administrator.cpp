#include "administrator.h"
#include "ui_administrator.h"
#include"dialogaction.h"
#include"mainwindow.h"
#include<QWheelEvent>
#include<QMouseEvent>
#include<QFileDialog>
#include<QColorDialog>
#include<QCompleter>
#include<QMenu>
#include<QAction>
#include<QDialog>
#include<QLineEdit>
#include<QSettings>
#include<QInputDialog>

QString deskPath2="..//CONFIG2.ini";
administrator::administrator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::administrator)
{
    ui->setupUi(this);
    this->setWindowTitle("AdminWindow");

    dialogaction *action=new dialogaction;
    action->createdWidget(this->ui->textEdit);
    connect(action,SIGNAL(getText(QString)),this,SLOT(setText(QString)));

    //配置查找文件
     searchFile_ini = new QSettings("..//CONFIG2.ini",QSettings::IniFormat);
}

administrator::~administrator()
{
    delete ui;
}
void administrator::wheelEvent(QWheelEvent *event)
{
    if(event->delta()>0)
    {
        qDebug("get");
        ui->textEdit->zoomIn();
        qDebug("set");
    }
    else
    {
        ui->textEdit->zoomOut();
    }
}


void administrator::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        if(windowState()!=Qt::WindowFullScreen)
        {
            setWindowState(Qt::WindowFullScreen);
        }
        else
        {
            setWindowState(Qt::WindowNoState);
        }
    }
}

void administrator::on_actionSave_S_triggered()
{
    if (_filePath.isEmpty())
        on_actionSave_As_A_triggered();

    QFile f(_filePath);
    if (!f.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    f.write(ui->textEdit->toPlainText().toUtf8());//以纯文本方式的字符串形式表示
    f.close();
}

void administrator::on_actionSave_As_A_triggered()
{
    auto filePath
        = QFileDialog::getSaveFileName(this,
                                       "Open markdown",
                                       QString(),
                                       "Markdown files (*.md);;All files (*)");

    if (!filePath.isEmpty()) {
        QFile f(filePath);
        if (!f.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
        f.write(ui->textEdit->toPlainText().toUtf8());
        f.close();
        _filePath = filePath;
    }
}

void administrator::on_actionOpen_O_triggered()
{
    auto filePath
        = QFileDialog::getOpenFileName(this,
                                       "Open markdown",
                                       QString(),
                                       "Markdown files (*.md);;All files (*)");//打开文件

    if (!filePath.isEmpty()) {
        QFile f(filePath);//读取文件路径
        if (!f.open(QIODevice::ReadOnly | QIODevice::Text))//只读，行结束符转化为/n
            return;
        ui->textEdit->setText(f.readAll());//读取所有数据，隐式转化为QString
        f.close();//关闭文件对象
        _filePath = filePath;
    }
}

void administrator::on_actionColor_C_triggered()
{
    QColorDialog dialog;
    dialog.setOption(QColorDialog::ShowAlphaChannel);
    dialog.exec();
    QColor color=dialog.currentColor();
    ui->textEdit->setTextColor(color);
}

void administrator::on_actionBackGroundColor_B_triggered()
{
    QColorDialog dialog;
    dialog.setOption(QColorDialog::ShowAlphaChannel);
    dialog.exec();
    QColor color=dialog.currentColor();
    ui->textEdit->setTextBackgroundColor(color);
}

void administrator::setText(const QString &string)
{
    ui->textEdit->append(string);
}

void administrator::on_actionFile_Name_N_triggered()
{
    QFile f(deskPath2);//读取文件路径
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text))//只读，行结束符转化为/n
        return;
    ui->textEdit->setText(f.readAll());//读取所有数据，隐式转化为QString
    f.close();//关闭文件对象
    _filePath = deskPath2;
}

void administrator::on_actionIO_Name_I_triggered()
{
    QFile f(deskPath2);//读取文件路径
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text))//只读，行结束符转化为/n
        return;
    ui->textEdit->setText(f.readAll());//读取所有数据，隐式转化为QString
    f.close();//关闭文件对象
    _filePath = deskPath2;
}


void administrator::on_pushButton_2_clicked()
{
    ui->textEdit->clear();
}




