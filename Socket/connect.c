#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>

#define PORT 80  //定义一个端口号
#define REMOTE_IP "59.175.132.70"  //定义一个IP地址

int main(int argc, char *argv[])
{	    
	int sockfd;        
	struct sockaddr_in addr;  //定义 IPV4 套接字地址数据结构 addr	    
	if(argc != 2)		        
	{				        
		printf("请输入正确的IP地址字符串。\n");		    
		return 2;					    
	}						        
	if(sockfd = socket(AF_INET, SOCK_STREAM, 0) < 0) //建立一个 socket   
	{						            
		printf("创建套接字失败!\n");			
		return 1;					        
	}			    
	bzero(&addr,sizeof(struct sockaddr_in));     
	addr.sin_family = AF_INET;	
	addr.sin_port = htons(PORT);	    
	addr.sin_addr.s_addr = inet_addr(argv[1]);  //从argv[1]中获得目标的IP地址 
	if(connect(sockfd, (struct sockaddr *)(&addr), sizeof(struct sockaddr))<0)
	{							        
		printf("连接失败!\n");					        
		return 0;						    
	}	       
	else	    
	{		            
		printf("连接成功!\n");		        
	}									  
	return 0;
}
