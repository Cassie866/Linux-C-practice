#include <iostream>
using namespace std;
 
int main()
{
	int n;
	while(cin>>n)
	{
		string s1,s2;
		int count=0,max=0;
		for(int i=0;i<n;++i)
		{
			cin>>s1>>s2;
			if(s2=="connect")
				++count;
			if(s2=="disconnect")
				--count;
			if(count>max)
				max=count;
		}
		cout<<max<<endl;
	}
	return 0;
 }
