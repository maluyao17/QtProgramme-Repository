#include<QApplication>
#include<Qdialog>
#include<QLabel>
int main(int argc,char* argv[])
{
    QApplication a(argc,argv);
    QDialog w;
    QLabel label(&w);
    label.setText("Hello world! 你好Qt");
    w.show();
    return a.exec();
}
