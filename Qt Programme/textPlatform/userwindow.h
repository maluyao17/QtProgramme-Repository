#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QMainWindow>
#include<QString>
#include<QSettings>
#include<QTextCursor>
#include<QtextCursor>



namespace Ui {
class UserWindow;
}
class CmdWindow;
class UserWindow : public QMainWindow
{
    Q_OBJECT
    QString _filePath;
public:
    explicit UserWindow(QWidget *parent = 0);
    ~UserWindow();


    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_actionOpen_O_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_actionLcdColor_L_triggered();

    void on_actionSave_Score_S_triggered();

private:
    QTextCursor cursor;
    Ui::UserWindow *ui;
    QSettings* file_ini;
    QSettings* IO_ini;
    QSettings* score_ini;
    QSettings* time_ini;
    QString file;
    QString IO;
    int score=0;

    CmdWindow *cmd;
};

#endif // USERWINDOW_H
