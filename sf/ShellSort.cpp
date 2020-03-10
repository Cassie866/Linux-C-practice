#include <iostream>
#include <vector>
using namespace std;

void ShellSort(vector<int>&v)
{
	int gap = v.size();
	while (1)
	{
		gap = (gap / 3) + 1;
		for (int i = gap; i < v.size(); i++)
		{
			int k = v[i];
			int j;
			for (j = i - gap; j >= 0; j = j - gap) 
			{
				if (k < v[j]) 
					v[j + gap] = v[j];
				else
					break;
			}
			v[j + gap] = k;
		}
		if (gap == 1) 
		{
			break;
		}
	}
}

int main()
{
	vector<int> v={2,5,7,1,3,0,9,8,4,6};
	ShellSort(v);
	for(auto &e:v)
	{
		cout<<e<<' ';
	}
	cout<<endl;
	return 0;
}
