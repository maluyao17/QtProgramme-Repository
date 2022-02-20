#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLineEdit;
class QDialog;

namespace Ui {
class MainWindow;
}

class MySyntaxHighlighter;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //遍历文档框架
    void showTextFrame();
    void setTextFont(bool checked);

    void insertTable();
    void insertList();
    void insertImage();

    //查找文本
    void textFind();
    //查找下一个
    void findNext();

private:
    Ui::MainWindow *ui;
    QLineEdit *lineEdit;
    QDialog *findDialog;
    MySyntaxHighlighter *highlighter;
};

#endif // MAINWINDOW_H
