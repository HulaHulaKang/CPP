#ifndef DATABASE_H
#define DATABASE_H
#include<classes/CS_Student.h>

struct Node
{
    Node*next;
    CS_Student stu;
};

class DataBase
{
private:
    Node* head;
    int totalnum;//总数
public:
    //构造函数
    DataBase();

    //获取数据成员
    int gettotal();

    //插入数据
    void insert(CS_Student);

    //重载下标运算符
    CS_Student operator[] (int);

    //删除一个节点
    void del(int x);//为了与delete(关键字)区分，写成del
};

#endif
