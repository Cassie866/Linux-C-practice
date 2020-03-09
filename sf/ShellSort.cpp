#include <iostream>
#include <vector>
using namespace std;

void ShellSort(vector<int>&v)
{
	int g=v.size();
	while(1)
	{
		g=g/3+1;
		for(int i=g;i<v.size();++i)
		{
			int k=v[i];
			int j;
			for(int j=i-g;j>=0;j=j-g)
			{
				if(k<v[j])
					v[j+g]=v[j];
				else
					break;
			}
			v[j+g]=k;
		}
		if(g==1)
			break;
	}
}


int main()
{
	vector<int> v;
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);
	v.push_back(2);
	v.push_back(4);
	v.push_back(8);
	v.push_back(1);
	v.push_back(0);
	v.push_back(9);
	v.push_back(6);
	ShellSort(v);
	for(auto &e:v)
	{
		cout<<e<<' ';
	}
	cout<<endl;
	return 0;
}
