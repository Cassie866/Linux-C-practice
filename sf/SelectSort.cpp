#include <iostream>
#include <vector>
using namespace std;

void SelectSort(vector<int>&v)
{
	for(int i=0;i<v.size();++i)
	{
		int max=0;
		for(int j=0;j<v.size()-i;++j)
		{
			if(v[j]>v[max])
				max=j;
		}
		int t=v[max];
		v[max]=v[v.size()-i-1];
		v[v.size()-i-1]=t;
	}
}


int main()
{
	vector<int> v={6,8,2,1,3,4,9,0,5,7};
	SelectSort(v);
	for(auto &e:v)
	{
		cout<<e<<' ';
	}
	cout<<endl;
	return 0;
}
