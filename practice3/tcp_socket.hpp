#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <assert.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

typedef struct sockaddr sockaddr;
typedef struct sockaddr_in sockaddr_in;
#define CHECK_RET(exp) if (!(exp)) {  return false;}

class TcpSocket 
{
public:  
	TcpSocket() : fd_(-1) {  }  
	TcpSocket(int fd) : fd_(fd) {  }  
	bool Socket() 
	{    
		fd_ = socket(AF_INET, SOCK_STREAM, 0);
		if (fd_ < 0) 
		{
			perror("socket");
			return false;    
		}    
		printf("open fd = %d\n", fd_);    
		return true;  
	}  
	bool Close() const 
	{    
		close(fd_);    
		printf("close fd = %d\n", fd_);    
		return true;  
	}  
	bool Bind(const std::string& ip, uint16_t port) const 
	{    
		sockaddr_in addr;    
		addr.sin_family = AF_INET;    
		addr.sin_addr.s_addr = inet_addr(ip.c_str());    
		addr.sin_port = htons(port);    
		int ret = bind(fd_, (sockaddr*)&addr, sizeof(addr));    
		if (ret < 0) 
		{
			perror("bind");
			return false;    
		}    
		return true;  
	}  
	bool Listen(int num) const 
	{    
		int ret = listen(fd_, num);    
		if (ret < 0) 
		{
			perror("listen");
			return false;    
		}    
		return true;  
	}  
	bool Accept(TcpSocket* peer, std::string* ip = NULL, uint16_t* port = NULL) const 
	{    
		sockaddr_in peer_addr;    
		socklen_t len = sizeof(peer_addr);    
		int new_sock = accept(fd_, (sockaddr*)&peer_addr, &len);    
		if (new_sock < 0)
		{
			perror("accept");
			return false;    
		}    
		printf("accept fd = %d\n", new_sock);    
		peer->fd_ = new_sock;    
		if (ip != NULL) 
		{
			*ip = inet_ntoa(peer_addr.sin_addr);    
		}    
		if (port != NULL) 
		{
			*port = ntohs(peer_addr.sin_port);    
		}    
		return true;  
	}
	bool Recv(std::string* buf) const 
	{    
		buf->clear();    
		char tmp[1024 * 10] = {0};    
		// [注意!] 这里的读并不算很严谨, 因为一次 recv 并不能保证把所有的数据都全部读完  参考 man 手册 MSG_WAITALL 节.     
		ssize_t read_size = recv(fd_, tmp, sizeof(tmp), 0);    
		if (read_size < 0) 
		{
			perror("recv");
			return false;    
		}    
		if (read_size == 0) 
		{
			return false;    
		}    
		buf->assign(tmp, read_size);    
		return true;  
	}  
	bool Send(const std::string& buf) const 
	{    
		ssize_t write_size = send(fd_, buf.data(), buf.size(), 0);  
		if (write_size < 0) 
		{
			perror("send");
			return false;    
		}    
		return true;  
	}  
	bool Connect(const std::string& ip, uint16_t port) const 
	{    
		sockaddr_in addr;    
		addr.sin_family = AF_INET;    
		addr.sin_addr.s_addr = inet_addr(ip.c_str());    
		addr.sin_port = htons(port);    
		int ret = connect(fd_, (sockaddr*)&addr, sizeof(addr));    
		if (ret < 0) 
		{
			perror("connect");
			return false;    
		}    
		return true;  
	}  
	int GetFd() const 
	{    
		return fd_;  
	}
private:  
	int fd_;
};
