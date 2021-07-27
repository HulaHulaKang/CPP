#include"classes/Student.h"

Student::Student():People()//默认构造函数
{
    ID="-1";
}


//有具体参数的构造函数
Student::Student(QString _ID,
                 QString _name="未指明",QString _gender="未指明",QString _Educational_background="未指明")
    :People(_name,_gender,_Educational_background)
{
    ID=_ID;
}


//复制构造函数
Student::Student(Student& A):People(A)
{
    ID=A.ID;
}
