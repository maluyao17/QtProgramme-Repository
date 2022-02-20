#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QLCDNumber>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void timerEvent(QTimerEvent *event);

private:
    Ui::Widget *ui;
    int id1,id2,id3;
    QLCDNumber *lcd;

private slots:
    void timeUpdate();
};

#endif // WIDGET_H
