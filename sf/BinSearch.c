#include <stdio.h>

int BinSearch(int key,int a[],int n) 
{
	int left,right,mid;
	left=0;
	right=n-1;
	while(left<=right)
	{
		mid=(left+right)/2;
		if(key<a[mid]) //key小于中间值时
			right=mid-1;//确定左子表范围
		if(key>a[mid]) //key 大于中间值时
			left=mid+1;//确定右子表范围
		if(key==a[mid])//当key等于中间值时，证明查找成功
		{
			printf("查找成功!  a[%d]=%d\n",mid,a[mid]);//输出査找元素在数组中的位置
			break; 
		}
	}
	if(left > right)
		printf("查找失败!\n");
	return 0;
}

int main()
{
	int key = 5;
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	BinSearch(key,a,10);
	return 0;
}
