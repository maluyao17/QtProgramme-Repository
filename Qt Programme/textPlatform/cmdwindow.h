#ifndef CMDWINDOW_H
#define CMDWINDOW_H

#include"userwindow.h"

#include <QProcess>
#include <QMainWindow>
#include <handleapi.h>
#include <QShortcut>
namespace Ui {
class CmdWindow;
}
class MainWindow;
class CmdWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit CmdWindow(QWidget *parent = 0);
    ~CmdWindow();


private:
    Ui::CmdWindow *ui;
    QProcess *process;
    QShortcut *key;

    UserWindow user;
    MainWindow *m;

protected:
    //拖动进入事件
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);

public slots:
    void write_cmd();
    void read_data();
    void finished_process();
    void error_process();
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
};

#endif // CMDWINDOW_H
