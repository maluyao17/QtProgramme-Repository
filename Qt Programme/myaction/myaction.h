#ifndef MYACTION_H
#define MYACTION_H
#include<QWidgetAction>

class QLineEdit; //前置声明
class MyAction : public QWidgetAction
{
    Q_OBJECT
public:
    explicit MyAction(QObject *parent=0);

protected:
    //声明函数，QWidgetAction类的虚函数
    QWidget*createdWidget(QWidget *parent);

signals:
    void getText(const QString &string);

private slots:
    void sendText();

private:
    //声明行编辑对象的指针
    QLineEdit *lineEdit;

};

#endif // MYACTION_H
