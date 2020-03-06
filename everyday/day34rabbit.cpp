#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<unsigned long> v(91);
	v[0]=1;
	v[1]=1;
	for(int i=2;i<91;++i)
	{
		v[i]=v[i-1]+v[i-2];
	}
	int n=0;
	while(cin>>n)
	{
		cout<<v[n]<<endl;
	}
	return 0;
}
