#include<iostream>
using namespace std;
//h:��������ŵ�����ⲽ��ĺ���
void h(int n, char A, char B, char C)
{
	if (n == 1)cout << A << "--->" << C<<endl;
	else {
		h(n - 1, A, C, B); cout << A << "--->" << C << endl; h(n - 1, B, A, C);
	}
}

int main()
{
	int n;char a = 'A', b = 'B', c = 'C';
	while (cin >> n)
	{
		h(n, a, b, c);
		cout << endl ;
	}
}