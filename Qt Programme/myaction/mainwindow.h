#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //向编辑器中添加文本
    void setText(const QString &string);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
