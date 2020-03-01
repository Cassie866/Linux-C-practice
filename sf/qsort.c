#include <stdio.h>

void Qsort(int *a, int left, int right)
{
	if(left >= right)return;
	int i = left;
	int j = right;
	int key = a[left];
	while(i < j)  /*控制在当组内寻找一遍*/
	{
		while(i < j && key <= a[j])
		{
			j--;/*向前寻找*/
		}
		a[i] = a[j];
		while(i < j && key >= a[i])
		{
			i++;
		}
		a[j] = a[i];
	}
	a[i] = key;/*当在当组内找完一遍以后就把中间数key回归*/
	Qsort(a, left, i - 1);/*最后用同样的方式对分出来的左边的小组进行同上的做法*/
	Qsort(a, i + 1, right);/*用同样的方式对分出来的右边的小组进行同上的做法*/
}

int main()
{
	int a[] = {57, 68, 59, 52, 72, 28, 96, 33, 24};  
	Qsort(a, 0, sizeof(a) / sizeof(a[0]));
	for(int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}
