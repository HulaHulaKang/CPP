#ifndef PEOPLE_H
#define PEOPLE_H
#include<QString>

class People
{
protected:
    QString name;//姓名
    QString gender ;//性别
    QString Educational_background;//学历
public:
    People();//默认构造函数
    People(QString _name,QString _gender,QString _edu);//有具体值的构造函数
    People(People&);//复制构造函数
};



#endif
