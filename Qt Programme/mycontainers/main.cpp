#include<QCoreApplication>
#include<QMap>
#include<QMultiMap>
#include<QDebug>
int main(int argc,char *argv[])
{
    QCoreApplication a(argc,argv);
    QMap<QString,int>map;
    //向one中插入1
    map["one"]=1;
    map["two"]=2;
    map["three"]=3;

    map.insert("seven",7);
    //获取键的值，如果使用[]，map中没有该键，那么会自动插入
    int value1=map["six"];
    qDebug()<<"value1:"<<value1;
    qDebug()<<"contains 'six'?"<<map.contains("six");
    //使用value函数获取键值，键不存在时不会自动插入
    int value2=map.value("five");
    qDebug()<<"value2:"<<value2;
    qDebug()<<"contains 'five'?"<<map.contains("five");
    //当键不存在时，value()默认返回0，这里可以设定该值，比如这里设置9
    int value3=map.value("nine",9);
    qDebug()<<"value3:"<<value3;
    //map如果重新给该键设置了值，以前的会被擦除
    map.insert("ten",10);
    map.insert("ten",100);
    qDebug()<<"ten:"<<map.value("ten");
    //使用insertMulti()函数来实现一键多值，然后使用values()函数来获取值的列表
    map.insertMulti("two",2);
    map.insertMulti("two",4);
    QList<int> values=map.values("two");
    qDebug()<<"two:"<<values;
    //用QMultiMap来实现一键多值
    QMultiMap<QString,int>map1,map2,map3;
    map1.insert("values",1);
    map1.insert("values",2);
    map2.insert("values",3);
    map3=map1+map2;
    QList<int>myValues=map3.values("values");
    qDebug()<<"the values are:";
    for(int i=0;i<myValues.size();i++)
    {
        qDebug()<<myValues.at(i);
    }
    return a.exec();
}
