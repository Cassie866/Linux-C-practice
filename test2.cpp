#include <iostream>
#include <unistd.h>
#include <stdlib.h>
using namespace std;
int main()
{
	int id =fork();
	if(id < 0)
	{
		perror("fork");
		return 1;
	}
	else if(id == 0)
	{
		cout<<"i am child,pid:"<<getpid()<<endl;
		sleep(10);
	}
	else
	{
		cout<<"i am parent,pid:"<<getpid()<<endl;
		sleep(3);
		exit(0);
	}
	return 0;
}

