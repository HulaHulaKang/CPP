#ifndef CS_STUDENT_H
#define CS_STUDENT_H
/*
CS_Student类的数据成员有:
QString name;                       姓名
QString gender;                     性别
QString Educational_background;     学历
int ID;                             学号
int rank;                           名次
*/



#include"classes/Student.h"
class CS_Student:public Student
{
protected:
        int rank;//名次
public:
        //构造函数
        CS_Student();
        CS_Student(int _rank,QString _ID,QString _name,QString _gender,QString _edu);
        CS_Student(CS_Student&);

        //获取数据成员
        int getrank();
        QString getID();
        QString getgender();
        QString getname();
        QString getEduBkg();

};



#endif
