#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMap>
#include<QErrorMessage>
#include<QSettings>
#include<QString>
#include"administrator.h"
#include"cmdwindow.h"

namespace Ui {
class MainWindow;
}
class  QErrorMessage;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    administrator admin2;
    CmdWindow cmd;

private slots:
    void on_pushButton_6_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    QErrorMessage *errordlg;
    QErrorMessage *errodlg2;//登录错误
    QErrorMessage *errodlg3;//管理员登录错误

    QSettings *new_ini;

    QString newPass;
    bool remeberPassword=false;

    //记住密码setting
    QSettings *rem_ini;
    QSettings *rem_ini2;
    QString remStr;
    QString remPass;
    QSettings *rem_pass;

    //用户端setting
    QSettings *userName_ini;
    QSettings *userPass_ini;
    QString t="t";
    QString f="f";
    QVariant v1=t;
    QVariant v2=f;



};

#endif // MAINWINDOW_H
