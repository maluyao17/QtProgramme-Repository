#ifndef TIMES_H
#define TIMES_H

#include <QObject>

class times : public QObject
{
    Q_OBJECT
public:
    static times*restart();
    void addtime(myScene&s);
private:
    explicit times(QObject *parent = nullptr);

signals:
    void update();
public slots:
private:
    static times*time;
};

#endif // TIMES_H
