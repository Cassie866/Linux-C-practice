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
	vector<int> v={3,2,5,4,8,6,7,9,0,1};
	InsertSort(v);
	for(auto &e:v)
	{
		cout<<e<<' ';
	}
	cout<<endl;
	return 0;
}
