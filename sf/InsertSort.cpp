#include <iostream>
#include <vector>
using namespace std;

void InsertSort(vector<int>&v)
{
	for(int i=1;i<v.size();++i)
	{
		int k=v[i];
		int j;
		for(j=i-1;j>=0;--j)
		{
			if(k<v[j])
				v[j+1]=v[j];
			else
				break;
		}
		v[j+1]=k;
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
	InsertSort(v);
	for(auto &e:v)
	{
		cout<<e<<' ';
	}
	cout<<endl;
	return 0;
}
