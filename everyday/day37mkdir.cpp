#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
 
int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> v(n);
		for (int i = 0; i < n; i++)
		{
			cin>>v[i];
		}
		sort(v.begin(), v.end());
		vector<bool> flag(n, true);
		for (int i = 0; i < v.size()-1; i++)
		{
			if (v[i] == v[i + 1])
				flag[i] = false;
			if (v[i] == v[i + 1].substr(0, v[i].size())&& v[i+1][v[i].size()] == '/')
				flag[i] = false;
		}
		for (int i = 0; i < n; i++)
		{
			if(flag[i])
				cout << "mkdir -p"  << ' ' << v[i] << endl;
		}
		cout << endl;
	}
	return 0;
}
