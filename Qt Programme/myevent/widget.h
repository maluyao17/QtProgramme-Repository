#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class MyLineEdit;
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    bool eventFilter(QObject *watched, QEvent *event);
    ~Widget();

protected:
    void keyPressEvent(QKeyEvent *event);
private:
    MyLineEdit *lineEdit;
    Ui::Widget *ui;
};

#endif // WIDGET_H
