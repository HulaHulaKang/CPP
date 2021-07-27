#include"classes/DataBase.h"

DataBase::DataBase()
{
    head=NULL;
    totalnum=0;
}

int DataBase::gettotal(){return totalnum;}

void DataBase::insert(CS_Student s)
{
    Node* N=new Node;
    N->next=head;N->stu=s;
    head=N;
    totalnum+=1;
}

CS_Student DataBase::operator[] (int x)
{
    //totalnum=0时不能调用此函数
    int i=0;
    Node *h=head;
    while(i<x)
    {
        h=h->next;
        ++i;
    }
    return h->stu;
}

void DataBase::del(int x)
{
    //x必须小于totalnum
    Node *h=head,*h1=NULL;

    if(x>0)
    {
        for(int i=0;i<x;++i)
        {
            if(i==x-1)h1=h;
            h=h->next;
        }
        h1->next=h->next;

    }

    if(x==0)
    {
        head=head->next;
    }

    delete h;
    totalnum--;
}
