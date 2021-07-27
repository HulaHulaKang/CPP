#include"classes/People.h"
People::People()//默认构造函数
{
    gender="未指明";
    name="未指明";
    Educational_background="未指明";
}


People::People(People &A)//复制构造函数
{
    gender=A.gender;
    name=A.name;
    Educational_background=A.Educational_background;
}

People::People(QString _name,QString _gender="未指明",QString _edu="未指明")//有具体值的构造函数
{
    name=_name;
    gender=_gender;
    Educational_background=_edu;
}
