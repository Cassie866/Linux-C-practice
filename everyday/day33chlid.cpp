#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1,s2;
	while(cin>>s1>>s2)
	{
		int n=0;
		int p=0;
		while(p+s2.size()<=s1.size())
		{
			if(s1.substr(p,s2.size())==s2)
			{
				++n;
				p+=s2.size(); 
			}
			else
			{
				++p;
			}
		}
		cout<<n<<endl;
	}
	return 0;
}
