#include"classes/CS_Student.h"

CS_Student::CS_Student():Student()//默认构造函数
{
    rank=-1;
}

//有具体参数的构造函数
CS_Student::CS_Student(int _rank,QString _ID="-1",
                 QString _name="未指明",QString _gender="未指明",QString _Educational_background="未指明")
    :Student(_ID,_name,_gender,_Educational_background)
{
    rank=_rank;
}


CS_Student::CS_Student(CS_Student& A):Student(A)//复制构造函数
{
    rank=A.rank;
}



int CS_Student::getrank(){return rank;};
QString CS_Student::getID(){return ID;};
QString CS_Student::getgender(){return gender;};
QString CS_Student::getname(){return name;};
QString CS_Student::getEduBkg(){return Educational_background;};
