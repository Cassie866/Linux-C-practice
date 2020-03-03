#include <iostream>
#include <string>
using namespace std;

int main()
{    
	string s1,s2;    
	getline(cin,s1);    
	getline(cin,s2);    
	for(auto &e:s2)    
	{        
		while(s1.find(e)!=-1)        
		{            
			s1.erase(s1.find(e),1);        
		}    
	}    
	cout<<s1<<endl;    
	return 0;
}
