#ifndef MYACTION_H
#define MYACTION_H
#include<QWidgetAction>

class QLineEdit; //前置声明
class dialogaction : public QWidgetAction
{
    Q_OBJECT
public:
    explicit dialogaction(QObject *parent=0);
    //声明函数，QWidgetAction类的虚函数
    QWidget*createdWidget(QWidget *parent);

protected:


signals:
    void getText(const QString &string);

private slots:
    void sendText();

private:
    //声明行编辑对象的指针
    QLineEdit *lineEdit;

};

#endif // MYACTION_H
