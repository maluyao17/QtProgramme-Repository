#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"cmdwindow.h"
#include<QInputDialog>
#include<QString>
#include<QMessageBox>
#include<QErrorMessage>
#include <QSettings>
#include<QDebug>


QString deskPath="..//CONFIG.ini";
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setWindowTitle("LoginWindow");
    QSettings* m_ini = new QSettings("..//CONFIG.ini",QSettings::IniFormat);
    QSettings* n_ini = new QSettings("..//CONFIG.ini",QSettings::IniFormat);
    rem_pass=new QSettings("..//CONFIG.ini",QSettings::IniFormat);
    QString name=m_ini->value("UserName").toString();
    QString pass=n_ini->value("PassWord").toString();
    QString rempass=rem_pass->value("remberPassword").toString();

    if(rempass=="t")
    {
        ui->lineEdit->setText(name);
        ui->lineEdit_2->setText(pass);
        ui->checkBox->setChecked(true);
    }
    else
    {
        ui->lineEdit->setText(name);
        ui->checkBox->setChecked(false);
    }
    QRegExp rx( "^[A-Za-z]+$");
    QValidator *validator1=new QRegExpValidator(rx,this);
    QValidator *validator2=new QIntValidator(1000000000,9999999999,this);
    ui->lineEdit->setValidator(validator1);
    ui->lineEdit_2->setValidator(validator2);

    errordlg=new QErrorMessage(this);//注册错误
    errodlg2=new QErrorMessage(this);//登录错误
    errodlg3=new QErrorMessage(this);//管理员登录错误

    //状态栏
    ui->statusBar->showMessage(tr("Computer Visual test platform 1.0.1"),2000);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_6_clicked()
{
    QString str=QInputDialog::getText(this,tr("Register"),tr("UserName:"),QLineEdit::Normal,tr("name"));
    QString num=QInputDialog::getText(this,tr("Register"),tr("Password:"),QLineEdit::Normal,tr("password"));
    if(str==" "||num==" ")
    {

        errordlg->setWindowTitle(tr("error"));
        errordlg->showMessage(tr("Invalid user name and password!"));
    }
    else
    {
            rem_ini=new QSettings("..//CONFIG.ini",QSettings::IniFormat);
            rem_ini->setValue("UserName",str);
            rem_ini2=new QSettings("..//CONFIG.ini",QSettings::IniFormat);
            rem_ini2->setValue("PassWord",num);

        qDebug()<<"ip:"<<str<<newPass;
        QMessageBox msgbox(
                QMessageBox::Information,
                "tips",
                "Success Register!",
                QMessageBox::Ok,
                this);
       msgbox.setStyleSheet("QLabel{"
                         "min-width: 200px;"
                         "min-height: 100px; "
                         "}");

        msgbox.exec();
    }
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{

    if(ui->checkBox->isChecked())
    {

        rem_ini=new QSettings("..//CONFIG.ini",QSettings::IniFormat);
        rem_ini->setValue("UserName",ui->lineEdit->text());
        rem_ini2=new QSettings("..//CONFIG.ini",QSettings::IniFormat);
        rem_ini2->setValue("PassWord",ui->lineEdit_2->text());
        rem_pass->setValue("remberPassword",v1.toString());
        qDebug()<<remStr;

    }
    else
    {
        ui->lineEdit_2->clear();
        rem_pass->setValue("remberPassword",v2);
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    userName_ini=new QSettings("..//CONFIG.ini",QSettings::IniFormat);
    QString str1=userName_ini->value("UserName").toString();
    userPass_ini=new QSettings("..//CONFIG.ini",QSettings::IniFormat);
    QString str2=userPass_ini->value("PassWord").toString();
    QString str3=ui->lineEdit->text();
    QString str4=ui->lineEdit_2->text();
    if(str3==str1&&str4==str2)
    {
        int ret1=QMessageBox::information(this,tr("Tips"),tr("接下来需要检测您代码的正确性，请利用命令行执行!"),QMessageBox::Ok);
        if(ret1==QMessageBox::Ok)
        {
            cmd.show();
            this->hide();
        }
    }
    else
    {

        errodlg2->setWindowTitle("login error:");
        errodlg2->showMessage(tr("error!"));
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    QString str1=ui->lineEdit->text();
    QString str2=ui->lineEdit_2->text();
    QString str3="administrator";
    QString str4="123456";
    if(str3==str1&&str4==str2)
    {
        admin2.show();
        this->hide();
        qDebug("get");
    }
    else
    {

        errodlg3->setWindowTitle("login error:");
        errodlg3->showMessage(tr("error!"));
    }
}

void CmdWindow::on_pushButton_3_clicked()
{
    MainWindow *m=new MainWindow;
    this->hide();
    m->show();
}

void administrator::on_pushButton_3_clicked()
{
    this->hide();
    MainWindow *m=new MainWindow;
    m->show();
}
