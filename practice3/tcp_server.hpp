#pragma once
#include <functional>
#include "tcp_socket.hpp"

typedef std::function<void (const std::string& req, std::string* resp)> Handler;

class TcpServer 
{
public:  
	TcpServer(const std::string& ip, uint16_t port) : ip_(ip), port_(port) {  }  
	bool Start(Handler handler) 
	{    
		// 1. 创建 socket;    
		CHECK_RET(listen_sock_.Socket());    
		// 2. 绑定端口号    
		CHECK_RET(listen_sock_.Bind(ip_, port_));    
		// 3. 进行监听    
		CHECK_RET(listen_sock_.Listen(5));    
		// 4. 进入事件循环    
		for (;;) 
		{
			// 5. 进行 accept
			TcpSocket new_sock;
			std::string ip;
			uint16_t port = 0;
			if (!listen_sock_.Accept(&new_sock, &ip, &port)) 
			{
				continue;      
			}
			printf("[client %s:%d] connect!\n", ip.c_str(), port);
			// 6. 进行循环读写
			for (;;) 
			{
				std::string req;
				// 7. 读取请求. 读取失败则结束循环
				bool ret = new_sock.Recv(&req);
				if (!ret) 
				{
					printf("[client %s:%d] disconnect!\n", ip.c_str(), port);
					// [注意!] 需要关闭 socket
					new_sock.Close();
					break;        
				}
				// 8. 计算响应
				std::string resp;
				handler(req, &resp);
				// 9. 写回响应
				new_sock.Send(resp);
				printf("[%s:%d] req: %s, resp: %s\n", ip.c_str(), port,req.c_str(), resp.c_str());      
			}    
		}    
		return true;  
	}
private:  
	TcpSocket listen_sock_;  
	std::string ip_;  
	uint64_t port_;
};
