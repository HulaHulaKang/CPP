#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include<classes/People.h>
class Student:public People
{
protected:
    QString ID;//学号
public:
    Student();//默认构造函数
    Student(Student&);//复制构造函数
    Student(QString _ID,QString _name,QString _gender,QString _edu);//有具体参数的构造函数
};



#endif
