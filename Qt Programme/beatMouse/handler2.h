#ifndef HANDLER2_H
#define HANDLER2_H

#include <QObject>

class handler2 : public QObject
{
    Q_OBJECT
public:
    static handler2*getInstance2();
    void DecreaseScore();
private:

    explicit handler2(QObject *parent = nullptr);

signals:
    void unbeatMouse();
public slots:
private:
    static handler2* hand2;
};

#endif // HANDLER2_H
