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
