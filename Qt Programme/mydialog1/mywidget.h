#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include<QWizard>

namespace Ui {
class MyWidget;
}
class QErrorMessage;

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();
    QErrorMessage *errordlg;
public slots:
    void showChildDialog();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::MyWidget *ui;
    QWizardPage *creatPage1();
    QWizardPage *creatPage2();
    QWizardPage *creatPage3();
};

#endif // MYWIDGET_H
