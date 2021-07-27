/*
本程序实现了含小数的大数加减运算
*/

#include "类定义.h"
using std::cin;
using std::cout;
using std::endl;

//运算符为"+"时调用的函数
void add()
{
    //提示
    cout << "大数加法(含小数):" << endl;
    for (int i = 0; i < 45; ++i) cout << "+"; cout << endl;

    HighDegreeNum num_one, num_two, result, Zero;

    //Zero表示0
    Zero.intPart.insert(0); Zero.decPart.insert(0);

    //输入
    cout << "请输入加数一:";
    num_one.input();
    cout << "请输入加数二:";
    num_two.input();

    //正数加正数
    if (num_one.sym == Symbol::positive
        && num_two.sym == Symbol::positive)result = num_one + num_two;

    //负数加负数
    else if (num_one.sym == Symbol::negative
        && num_two.sym == Symbol::negative)
    {
        result = num_one + num_two; if (!(result == Zero))result.sym = Symbol::negative;
    }

    //小正数加大负数
    else if (num_one.sym == Symbol::positive
        && num_two.sym == Symbol::negative
        && num_two >= num_one) {
        result = num_two - num_one; if (!(result == Zero))result.sym = Symbol::negative;
    }

    //大正数加小负数
    else if (num_one.sym == Symbol::positive
        && num_two.sym == Symbol::negative
        && num_one > num_two)result = num_one - num_two;

    //小负数加大正数
    else if (num_one.sym == Symbol::negative
        && num_two.sym == Symbol::positive
        && num_two >= num_one) result = num_two - num_one;

    //大负数加小正数
    else if (num_one.sym == Symbol::negative
        && num_two.sym == Symbol::positive
        && num_one > num_two) {
        result = num_one - num_two; if (!(result == Zero))result.sym = Symbol::negative;
    }

    //去除无意义的零
    result.format();

    //输出
    cout << "程序运行完毕，两数的和为:";
    result.display();
    cout << endl;
    for (int i = 0; i < 45; ++i) cout << "+";
    cout << endl << endl;

}

//运算符为"-"时调用的函数
void subtract()
{
    //提示
    cout << "大数减法(含小数):" << endl;
    for (int i = 0; i < 45; ++i)cout << "-"; cout << endl;

    HighDegreeNum num_one, num_two, result, Zero;

    //Zero表示零
    Zero.intPart.insert(0); Zero.decPart.insert(0);

    //输入
    cout << "请输入被减数:";
    num_one.input();
    cout << "请输入减数:";
    num_two.input();

    //大正数减小正数
    if (num_one.sym == Symbol::positive
        && num_two.sym == Symbol::positive
        && num_one >= num_two) result = num_one - num_two;

    //小正数减大正数
    else if (num_one.sym == Symbol::positive
        && num_two.sym == Symbol::positive
        && num_two > num_one)
    {
        result = num_two - num_one;
        if (!(result == Zero))result.sym = Symbol::negative;
    }

    //负数减正数
    else if (num_one.sym == Symbol::negative
        && num_two.sym == Symbol::positive)
    {
        result = num_one + num_two;
        if (!(result == Zero))result.sym = Symbol::negative;
    }

    //正数减负数
    else if (num_one.sym == Symbol::positive
        && num_two.sym == Symbol::negative)result = num_one + num_two;

    //小负数减大负数
    else if (num_one.sym == Symbol::negative
        && num_two.sym == Symbol::negative
        && num_two >= num_one)  result = num_two - num_one;

    //大负数减小负数
    else if (num_one.sym == Symbol::negative
        && num_two.sym == Symbol::negative
        && num_one > num_two)
    {
        result = num_one - num_two; if (!(result == Zero))result.sym = Symbol::negative;
    }

    //输出
    cout << "程序运行完毕，两数的差为:";
    result.display();
    cout << endl;
    for (int i = 0; i < 45; ++i) cout << "-";
    cout << endl << endl;
}

//主函数
int main()
{
    cout << "请问你有多少组运算数据:";
    int n; cin >> n;
    if (n <= 0) { cout << "error"; return n; }
    for (int i = 0; i < 45; ++i)cout << "*"; cout << endl;
    cout << "若要做加法，请输入加号；若要做减法，请输入减号" << endl << endl;

    for (int i = 0; i < n; ++i)
    {
        cout << "请输入运算符:";
        char op; cin >> op;
        if (op == '+') add();

        if (op == '-') subtract();

    }
    return 0;
}
