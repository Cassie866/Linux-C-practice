#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a;
	while (cin >> a)
	{
		cout << a << " = ";
		for (int i=2;i<=a;++i)
		{
			while (a % i == 0)
			{
				if (a != i)
					cout << i << " * ";
				else
					cout << i;
				a = a / i;
			}
		}
		cout << endl;
	}
	return 0;
}
