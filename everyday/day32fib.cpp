#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
	vector<int> v(1000002);
	v[0]=1;
	v[1]=1;
	for(int i=2;i<=1000000;++i)
	{
		v[i]=v[i-1]+v[i-2];
		v[i]%=1000000;
	}
	int n;
	while(cin>>n)
	{
		if(n>=25)
		{
			cout<<setfill('0')<<setw(6)<<v[n]<<endl;
		}
		else
			cout<<v[n]<<endl;
	}
	return 0;
}
