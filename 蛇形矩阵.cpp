#include<iostream>
using namespace std;
int f(int x) { if (x == 1)return 1; else return f(x - 1) + x - 1; }//��x�еĵ�һ��Ԫ��
int g(int x, int m) { if (m == 1)return f(x); else return g(x, m - 1) + x + m - 1; }//��x�е�m��Ԫ��
int main()
{

	int x;
	int n;
	int m;
	while (cin >> x)
	{
		
		for (n = 1; 2 * x > (n+1 )* n; ++n) {}//������n
		for (int i = 1;i<=n; i++)//��i�е���� 
		{
			for (m = 1; g(i, m) < x&&g(i,m+1)<=x; ++m) { cout << g(i, m) << " "; }
			cout << g(i, m)<<endl;
		}
	}
}