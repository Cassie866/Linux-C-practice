#include <iostream>
#include <vector>
using namespace std;

int main()
{    
	int n;    
	cin>>n;    
	vector<int> v(n);    
	for(int i=0;i<n;++i)    
	{        
		cin>>v[i];    
	}    
	int sum=0;    
	int max=-1;    
	for(int i=0;i<v.size();++i)    
	{        
		if(sum>=0)
			sum+=v[i];        
		else        
			sum=v[i];                
		if(sum>max)
			max=sum;
	}    
	cout<<max<<endl;    
	return 0;
}
