#pragma once
#include<iostream>

//符号类
enum class Symbol :bool { negative, positive };

//结点类
//包含一个数位
struct Node
{
public:
    int data;
    Node* next;
    Node(int, Node*);
    Node(const Node&);
};

//长整数类
//存储一个符号
//和一个链表
class LongInt
{
    friend class HighDegreeNum;

private:
    Node* head;
    Symbol sym = Symbol::positive;
    int length = 0;
public:
    LongInt();
    ~LongInt();
    void insert(int);
    void display();
    void input();
    LongInt operator+ (LongInt&);
    LongInt operator- (LongInt&);
    bool operator< (LongInt);
    bool operator<= (LongInt);
    void format();
    LongInt putUpsideDown();
};

//高精度数类
//存储一个符号
//和两个LongInt(整数部分和小数部分)
class HighDegreeNum
{
    friend void add();
    friend void subtract();
private:LongInt intPart; LongInt decPart; Symbol sym = Symbol::positive;
public:
    HighDegreeNum();
    ~HighDegreeNum();
    void input();
    void display();
    HighDegreeNum operator+ (HighDegreeNum&);
    HighDegreeNum operator-(HighDegreeNum&);
    void format();
    bool operator> (HighDegreeNum);
    bool operator== (HighDegreeNum);
    bool operator>= (HighDegreeNum);
};





