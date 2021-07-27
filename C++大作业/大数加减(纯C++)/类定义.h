#pragma once
#include<iostream>

//������
enum class Symbol :bool { negative, positive };

//�����
//����һ����λ
struct Node
{
public:
    int data;
    Node* next;
    Node(int, Node*);
    Node(const Node&);
};

//��������
//�洢һ������
//��һ������
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

//�߾�������
//�洢һ������
//������LongInt(�������ֺ�С������)
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





