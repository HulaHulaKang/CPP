#include<iostream>
using namespace std;
int main()
//��������Ӧ����������ж��Ƿ���������ǻ������������YES���������������NO����
{
	int x,s,n; while (cin >> x)
	{
		n = 0;
		s = x;
		while (s)
		{
			n = 10 * n + s % 10;
			s /= 10;
		}
		cout << n<<endl;
		if (n == x)cout << "YES" << endl; else cout << "NO"<<endl;
		
	}
}