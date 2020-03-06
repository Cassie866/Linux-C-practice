#include <iostream>
using namespace std;

int ShouY(int month)
{
	int a[12]={2,1,1,2,1,2,1,2,2,2,1,2};
	return a[month-1];
}

int Days(int year,int month)
{
	int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if((year%4==0&&year%100!=0)||(year%400==0))
	{
		a[1]+=1;
	}
	return a[month-1];
}


int main()
{
	int year,month,day;
	int year2,month2,day2;
	while(cin>>year>>month>>day>>year2>>month2>>day2)
	{
		int sum=0;
		if(year==year2&&month==month2&&day==day2)
		{
			sum+=ShouY(month);
		}
		if(year==year2&&month==month2&&day!=day2)
		{
			sum+=(day2-day+1)*ShouY(month);
		}
		if(year==year2&&month!=month2)
		{
			sum+=(Days(year,month)-day+1)*ShouY(month);
			++month;
			while(month<month2)
			{
				sum+=ShouY(month);
				++month;
			}
			sum+=day2*ShouY(month2);
		}
		if(year!=year2)
		{
			sum+=(Days(year,month)-day+1)*ShouY(month);
			++month;
			if(month==13)               
			{
				++year;
				month=1;
			}
			while(year<=year2)
			{
				sum+=Days(year,month)*ShouY(month);
				++month;
				if(month==13)    
				{
					++year;
					month=1;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
