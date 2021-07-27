#include"类定义.h"
using std::cin;
using std::cout;
using std::endl;

//Node（结点）构造函数
Node::Node(int d = 0, Node* a = NULL) { data = d; next = a; }
Node::Node(const Node& temp) { data = temp.data; next = temp.next; }

//LongInt（长整数）构造函数、析构函数
LongInt::LongInt() { head = new Node; }
LongInt::~LongInt() {};

//在链表前端插入一个数，成为新的头节点
void LongInt::insert(int d)
{
    if (length == 0)head = new Node(d);
    else {
        Node* temp = new Node(d, head);
        head = temp;
    }
    length++;
}

//输入长整数，并存储链表（反向链表：低位在前，高位在后）
void LongInt::input() {

    char cache;
    cin >> cache;
    while (cache < '0' || cache>'9')
    {
        if (cache == '-')sym = Symbol::negative; cin >> cache;
    }
    while (true)
    {
        if (cache == '0')cache = getchar(); else break;
    }
    if (cache == '\n' || cache == '.') { insert(0); return; }
    insert(cache - '0');

    while (true)
    {
        cache = getchar();
        if (cache == '\n' || cache == '.') break;
        if (cache < '0' || cache>'9')continue;
        insert(cache - '0');
    }

}

//长整数的加法函数
LongInt LongInt::operator+ (LongInt& other)
{
    LongInt result;
    int temp = 0, i, m, n;
    n = length;
    m = other.length;
    Node* p = head, * q = other.head;

    for (i = 0; i < n && i < m; i++)
    {
        int d = p->data + q->data + temp;
        temp = d / 10;
        result.insert(d % 10);
        p = p->next;
        q = q->next;
    }
    for (; i < n; i++)
    {
        int d = p->data + temp;
        temp = d / 10;
        result.insert(d % 10);
        p = p->next;
    }
    for (; i < m; i++)
    {
        int d = q->data + temp;
        temp = d / 10;
        result.insert(d % 10);
        q = q->next;
    }
    if (temp != 0)
        result.insert(temp);
    result.format();
    return result;

}

//长整数的减法函数
LongInt LongInt::operator- (LongInt& other)
{
    LongInt result;
    int i, n, m;
    n = length;
    m = other.length;
    Node* p = head, * q = other.head;

    for (i = 0; i < m; i++)
    {
        int cache = p->data - q->data;
        if (cache < 0)
        {
            p->next->data -= 1; cache += 10;
        }
        result.insert(cache);
        p = p->next;
        q = q->next;
    }
    for (; i < n; i++)
    {
        int cache;
        cache = p->data;
        if (cache < 0 && p->next)
        {
            p->next->data--;
            cache += 10;
        }
        if (p->next == NULL && p->data == 0)break;
        result.insert(cache);
        p = p->next;
    }

    result.format();
    return result;
}

//将链表输出为长整数（带逗号）
void LongInt::display() {
    int k = 0;
    if (sym == Symbol::negative)cout << "-";
    Node* temp = head;
    while (temp)
    {
        cout << temp->data;
        temp = temp->next;
        k++;
        if (k % 3 == length % 3 && temp != NULL) cout << ",";

    }

}

//LongInt对运算符<=的重载
bool LongInt::operator<= (LongInt other)
{
    if (length < other.length)return 1;
    if (length > other.length)return 0;
    Node* p1 = head, * p2 = other.head;
    while (p1 != NULL)
    {
        if (p1->data < p2->data)return 1;
        if (p1->data > p2->data)return 0;
        p1 = p1->next;
        p2 = p2->next;
    }
    return 1;

}

//LongInt对运算符<的重载
bool LongInt::operator< (LongInt other)
{
    if (other <= *this)return 0;
    else return 1;
}

//去除链表开头的连续的0（适用于正向链表）
void LongInt::format()
{
    while (head->data == 0 && head->next != NULL)
    {
        Node* x = head; head = head->next; delete x; length--;
    };
    if (length == 0) insert(0);
    return;
}

//颠倒链表，在正向链表（高位在前，低位在后）和反向链表（低位在前，高位在后）之间转换
LongInt LongInt::putUpsideDown()
{
    LongInt result; Node* p = head;
    while (p != NULL)
    {
        result.insert(p->data); p = p->next;
    }
    return result;
}

//HighDegreeNum（高精度数）构造、析构函数
HighDegreeNum::HighDegreeNum() {}
HighDegreeNum::~HighDegreeNum() {}

//输入高精度数，存储为两个“长整数”（整数部分和小数部分）
void HighDegreeNum::input()
{
    char cache;
    cin >> cache;
    while (cache < '0' || cache>'9')
    {
        if (cache == '-')sym = Symbol::negative; cin >> cache;
    }
    while (cache == '0')cache = getchar();
    if (cache == '\n') { intPart.insert(0); decPart.insert(0); return; }
    if (cache == '.') intPart.insert(0);
    else
    {
        if (cache >= '0' && cache <= '9')intPart.insert(cache - '0');
        while (true)
        {
            cache = getchar();
            if (cache == '.') break;
            if (cache == '\n') { decPart.insert(0); return; }
            if (cache < '0' || cache>'9')continue;
            intPart.insert(cache - '0');

        }
    }



    cin >> cache;
    while (cache < '0' || cache>'9')cin >> cache;
    if (cache == '\n') { decPart.insert(0); return; }
    while (true)
    {
        if (cache == '\n')break;
        if (cache < '0' || cache>'9')continue;
        decPart.insert(cache - '0');
        cache = getchar();
    }
    //remove meaningless "0"
    while (decPart.head->data == 0)
    {


        Node* x = decPart.head;
        decPart.head = decPart.head->next;
        delete x;
        decPart.length--;

        if (decPart.length == 0) { decPart.insert(0); break; }

    }

}

//输出高精度数
void HighDegreeNum::display()
{
    if (sym == Symbol::negative)cout << "-";
    intPart.display();
    if (decPart.length == 1 && decPart.head->data == 0) return;
    else
    {
        cout << ".";
        Node* temp = decPart.head;
        while (temp)
        {
            cout << temp->data;
            temp = temp->next;

        }
    }
}

//高精度数的加法函数
HighDegreeNum HighDegreeNum::operator+ (HighDegreeNum& other)
{
    HighDegreeNum result;
    int a = decPart.length;
    int b = other.decPart.length;
    int n, m;
    LongInt longer, shorter;

    if (a < b) { n = b; m = a; longer = other.decPart; shorter = decPart; }
    else { n = a; m = b; longer = decPart; shorter = other.decPart; }
    Node* p = longer.head, * q = shorter.head;
    for (int i = 0; i < n - m; ++i)
    {
        result.decPart.insert(p->data);
        p = p->next;
    }
    int cache = 0;
    for (int i = 0; i < m; ++i)
    {
        cache = cache + p->data + q->data;
        if (cache > 9) { cache -= 10; result.decPart.insert(cache); cache = 1; }
        else { result.decPart.insert(cache); cache = 0; }
        p = p->next;
        q = q->next;
    }

    result.intPart = intPart + other.intPart;
    LongInt temp = result.intPart.putUpsideDown();
    if (cache == 1)
    {
        Node* x = temp.head;
        while (true)
        {
            if (x == NULL) { x = new Node(1);  temp.length++; break; }
            x->data++;
            if (x->data == 10) { x->data = 0; x = x->next; continue; }
            else { cache = 0; break; }
        }
    }
    result.intPart = temp.putUpsideDown();
    result.format();
    return result;
}

//高精度数的减法函数
HighDegreeNum HighDegreeNum::operator-(HighDegreeNum& other)
{
    HighDegreeNum result;
    //decPart
    int m = decPart.length;
    int n = other.decPart.length;
    for (int i = 0; i < n - m; ++i)decPart.insert(0);
    for (int i = 0; i < m - n; ++i)other.decPart.insert(0);
    int a = decPart.length;
    int cache = 0;
    Node* p = decPart.head;
    Node* q = other.decPart.head;
    for (int i = 0; i < a; ++i)
    {
        cache = p->data - cache - q->data;
        if (cache < 0) { cache += 10; result.decPart.insert(cache); cache = 1; }
        else { result.decPart.insert(cache); cache = 0; }
        p = p->next;
        q = q->next;
    }

    if (cache == 1)
    {
        Node* x = intPart.head;
        while (true)
        {
            if (x->data != 0) { x->data--; break; }
            else x->data = 9;
            x = x->next;
        }
    }
    result.intPart = intPart - other.intPart;
    result.format();
    return result;
}

//HighDegreeNum对运算符>的重载
bool HighDegreeNum::operator>(HighDegreeNum other)
{
    if (intPart < other.intPart)return 0;
    if (other.intPart < intPart)return 1;
    LongInt x1 = decPart, x2 = other.decPart;
    int m = x1.length;
    int n = x2.length;
    for (int i = 0; i < n - m; ++i)x1.insert(0);
    for (int i = 0; i < m - n; ++i)x2.insert(0);
    if (x1 <= x2)return 0;
    return 1;
}

//HighDegreeNum对运算符==的重载
bool HighDegreeNum::operator== (HighDegreeNum other)
{
    if (*this > other)return 0;
    if (other > *this)return 0;
    else return 1;
}

//HighDegreeNum对运算符>=的重载
bool HighDegreeNum::operator>= (HighDegreeNum other)
{
    if (*this > other)return 1;
    if (*this == other)return 1;
    return 0;
}

//去除整数部分前导0和小数部分后导0
void HighDegreeNum::format()
{
    intPart.format();
    LongInt temp = decPart.putUpsideDown();
    temp.format();
    decPart = temp.putUpsideDown();
    return;
}
