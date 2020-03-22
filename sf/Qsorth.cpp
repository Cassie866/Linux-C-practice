#include <iostream>
#include <vector>
using namespace std;

int Partion(vector<int>&v,int left,int right)
{
	int begin=left;
	int end=right;
	int value=v[right];
	int temp;
	while(begin<end)
	{
		while(begin<end&&v[begin]<=value)
			begin++;
		while(begin<end&&v[end]>=value)
			end--;
		temp=v[begin];
		v[begin]=v[end];
		v[end]=temp;
	}
	temp=v[begin];
	v[begin]=v[right];
	v[right]=temp;
	return begin;
}

void Qsort(vector<int>&v,int left,int right)
{
	if(left>=right)
		return;
	int div=Partion(v,left,right);
	Qsort(v,left,div-1);
	Qsort(v,div+1,right);
}




int main()
{
	vector<int> v={1,5,3,7,8,9,4,2,0,6};
	Qsort(v,0,9);
	for(auto&e:v)
	{
		cout<<e<<' ';
	}
	cout<<endl;
	return 0;
}
