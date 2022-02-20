#include "mywidget.h"
#include <QApplication>
#include"mydialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyDialog mydialog;
    //判断dialog的执行结果，即exec的返回值
    if(mydialog.exec()==QDialog::Accepted)
    {
        MyWidget w;
        w.show();
        return a.exec();
    }
    else
    {
        return 0;
    }
    return a.exec();
}
