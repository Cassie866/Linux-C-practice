#include <iostream>
#include <vector>
using namespace std;

int BinSearch(vector<int>&v,int key)
{
	int left,right,mid;
	left=0;
	right=v.size()-1;
	while(left<=right)
	{
		mid=(left+right)/2;
		if(key<v[mid]) //key小于中间值时
			right=mid-1;//确定左子表范围
		if(key>v[mid]) //key 大于中间值时
			left=mid+1;//确定右子表范围
		if(key==v[mid])//当key等于中间值时，证明查找成功
		{
			return mid;
		}
	}
	if(left > right)
		return -1;
}

int main()
{
	    int key = 5;
	    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
	    cout<<BinSearch(v,key)<<endl;
	    return 0;
}
