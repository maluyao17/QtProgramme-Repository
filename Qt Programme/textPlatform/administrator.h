#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include"dialogaction.h"
#include <QMainWindow>
#include<QSettings>

namespace Ui {
class administrator;
}



class administrator : public QMainWindow
{
    Q_OBJECT
    QString _filePath;

public:
    explicit administrator(QWidget *parent = 0);
    dialogaction dlgaction;
    ~administrator();

protected:
    void mouseDoubleClickEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
private slots:
    void on_actionSave_S_triggered();

    void on_actionSave_As_A_triggered();

    void on_actionOpen_O_triggered();

    void on_actionColor_C_triggered();

    void on_actionBackGroundColor_B_triggered();

    void setText(const QString &string);

    void on_actionFile_Name_N_triggered();

    void on_actionIO_Name_I_triggered();

    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::administrator *ui;

    //配置查找
    QSettings *searchFile_ini;
};

#endif // ADMINISTRATOR_H
