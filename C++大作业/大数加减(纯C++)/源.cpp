/*
������ʵ���˺�С���Ĵ����Ӽ�����
*/

#include "�ඨ��.h"
using std::cin;
using std::cout;
using std::endl;

//�����Ϊ"+"ʱ���õĺ���
void add()
{
    //��ʾ
    cout << "�����ӷ�(��С��):" << endl;
    for (int i = 0; i < 45; ++i) cout << "+"; cout << endl;

    HighDegreeNum num_one, num_two, result, Zero;

    //Zero��ʾ0
    Zero.intPart.insert(0); Zero.decPart.insert(0);

    //����
    cout << "���������һ:";
    num_one.input();
    cout << "�����������:";
    num_two.input();

    //����������
    if (num_one.sym == Symbol::positive
        && num_two.sym == Symbol::positive)result = num_one + num_two;

    //�����Ӹ���
    else if (num_one.sym == Symbol::negative
        && num_two.sym == Symbol::negative)
    {
        result = num_one + num_two; if (!(result == Zero))result.sym = Symbol::negative;
    }

    //С�����Ӵ���
    else if (num_one.sym == Symbol::positive
        && num_two.sym == Symbol::negative
        && num_two >= num_one) {
        result = num_two - num_one; if (!(result == Zero))result.sym = Symbol::negative;
    }

    //��������С����
    else if (num_one.sym == Symbol::positive
        && num_two.sym == Symbol::negative
        && num_one > num_two)result = num_one - num_two;

    //С�����Ӵ�����
    else if (num_one.sym == Symbol::negative
        && num_two.sym == Symbol::positive
        && num_two >= num_one) result = num_two - num_one;

    //������С����
    else if (num_one.sym == Symbol::negative
        && num_two.sym == Symbol::positive
        && num_one > num_two) {
        result = num_one - num_two; if (!(result == Zero))result.sym = Symbol::negative;
    }

    //ȥ�����������
    result.format();

    //���
    cout << "����������ϣ������ĺ�Ϊ:";
    result.display();
    cout << endl;
    for (int i = 0; i < 45; ++i) cout << "+";
    cout << endl << endl;

}

//�����Ϊ"-"ʱ���õĺ���
void subtract()
{
    //��ʾ
    cout << "��������(��С��):" << endl;
    for (int i = 0; i < 45; ++i)cout << "-"; cout << endl;

    HighDegreeNum num_one, num_two, result, Zero;

    //Zero��ʾ��
    Zero.intPart.insert(0); Zero.decPart.insert(0);

    //����
    cout << "�����뱻����:";
    num_one.input();
    cout << "���������:";
    num_two.input();

    //��������С����
    if (num_one.sym == Symbol::positive
        && num_two.sym == Symbol::positive
        && num_one >= num_two) result = num_one - num_two;

    //С������������
    else if (num_one.sym == Symbol::positive
        && num_two.sym == Symbol::positive
        && num_two > num_one)
    {
        result = num_two - num_one;
        if (!(result == Zero))result.sym = Symbol::negative;
    }

    //����������
    else if (num_one.sym == Symbol::negative
        && num_two.sym == Symbol::positive)
    {
        result = num_one + num_two;
        if (!(result == Zero))result.sym = Symbol::negative;
    }

    //����������
    else if (num_one.sym == Symbol::positive
        && num_two.sym == Symbol::negative)result = num_one + num_two;

    //С����������
    else if (num_one.sym == Symbol::negative
        && num_two.sym == Symbol::negative
        && num_two >= num_one)  result = num_two - num_one;

    //������С����
    else if (num_one.sym == Symbol::negative
        && num_two.sym == Symbol::negative
        && num_one > num_two)
    {
        result = num_one - num_two; if (!(result == Zero))result.sym = Symbol::negative;
    }

    //���
    cout << "����������ϣ������Ĳ�Ϊ:";
    result.display();
    cout << endl;
    for (int i = 0; i < 45; ++i) cout << "-";
    cout << endl << endl;
}

//������
int main()
{
    cout << "�������ж�������������:";
    int n; cin >> n;
    if (n <= 0) { cout << "error"; return n; }
    for (int i = 0; i < 45; ++i)cout << "*"; cout << endl;
    cout << "��Ҫ���ӷ���������Ӻţ���Ҫ�����������������" << endl << endl;

    for (int i = 0; i < n; ++i)
    {
        cout << "�����������:";
        char op; cin >> op;
        if (op == '+') add();

        if (op == '-') subtract();

    }
    return 0;
}
