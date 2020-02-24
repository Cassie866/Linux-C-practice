#pragma once
#include "udp_socket.hpp"
#include <functional>

typedef std::function<void(const std::string&,std::string*resp)> Handler;

class UdpServer
{
	public:
	UdpServer()
	{
		assert(_sock.Socket());
	}

	~UdpServer()
	{
		_sock.Close();
	}
	bool Start(const std::string& ip, uint16_t port, Handler handler) 
	{    
		// 1. 创建 socket    
		// 2. 绑定端口号    
		bool ret = _sock.Bind(ip, port);    
		if (!ret) 
		{
			return false;    
		}    
		// 3. 进入事件循环    
		for (;;) 
		{
			// 4. 尝试读取请求
			std::string req;
			std::string remote_ip;
			uint16_t remote_port = 0;
			bool ret = _sock.RecvFrom(&req, &remote_ip, &remote_port);
			if (!ret) 
			{
				continue;
			}
			std::string resp;
			// 5. 根据请求计算响应
			handler(req, &resp);
			// 6. 返回响应给客户端
			_sock.SendTo(resp, remote_ip, remote_port);
			printf("[%s:%d] req: %s, resp: %s\n", remote_ip.c_str(), remote_port,req.c_str(), resp.c_str());    
		}    
		_sock.Close();    
		return true;
	}

private:	
	UdpSocket _sock;
};
