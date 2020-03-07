#include <iostream>
#include <vector>
using namespace std;

int main()
{
	    vector<unsigned long long> v(80);
	        v[0]=1;
		    v[1]=1;
		        for(int i=2;i<80;++i)
				    {
					            v[i]=v[i-1]+v[i-2];
						        }
							    int from,to;
							        while(cin>>from>>to)
									    {
										            unsigned long long sum=0;
											            for(int i=from;i<=to;++i)
													            {
															                sum+=v[i-1];
																	        }
																		        cout<<sum<<endl;
																			    }
																			        return 0;
}

