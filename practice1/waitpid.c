#include <sys/types.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
  pid_t pid;       
  if((pid=fork())<0)  //创建子进程失败
  {
    perror("创建子进程失败！\n");
    exit(0);
                                
  }
  else if(pid==0)  //进入子进程
  {
    if((pid=fork())<0)
    {
      perror("创建子进程失败！\n");
      exit(0);
    }
    else if(pid>0)
    {
      exit(0);
    }     
    else  
    {
      sleep(2);
      printf("这是第二个子进程，parent pid=%d\n",getppid());
      exit(0);                                                                          
    }
  }  
  if(waitpid(pid,NULL,0)!=pid)
  {
    perror("waitpid 销毁进程失败！\n");
    exit(0);                                      
  }
  exit(0);
  return 0;
}
