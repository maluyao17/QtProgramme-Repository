#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void on_textEdit_textChanged();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLabel *permanet;
};

#endif // MAINWINDOW_H
