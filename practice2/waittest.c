#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

int main()
{
	pid_t pid;
	if((pid=fork())==-1)
	{
		perror("fork");
		exit(1);
	}
	if(pid==0)
	{
		sleep(20);
		exit(10);
	}
	else
	{
		int st;
		int ret = wait(&st);
		if(ret>0&&(st&0x7f)==0)
		{
			printf("child exit code:%d\n",(st>>8)&0xff);
		}
		else if(ret > 0)
		{
			printf("sig code:%d\n",st&0x7f);
		}
	}
}
