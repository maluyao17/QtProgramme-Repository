#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QTimer>
#include <QMainWindow>
#include  <myscene.h>
#include<QCloseEvent>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void closeEvent(QCloseEvent*event);//重写关闭事件

private slots:
    void UpdateScore();
    void UpdateScore2();
    void startTime();
    void stopTime();
    void pauseTime();
private:
    Ui::MainWindow *ui;
    myScene*sc;
    //static int num;
    int score;
    int cnt;
    QTimer* ptimer2;

};

#endif // MAINWINDOW_H
