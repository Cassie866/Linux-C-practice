#pragma once
#include "udp_socket.hpp"

class UdpClient
{
public:
	UdpClient(const std::string& ip, uint16_t port) 
	: _ip(ip), _port(port) 
	{    
		assert(_sock.Socket());  
	}  
	~UdpClient() 
	{    
		_sock.Close();  
	}  
	bool RecvFrom(std::string* buf) 
	{    
		return _sock.RecvFrom(buf); 
	}  
	bool SendTo(const std::string& buf) 
	{
		return _sock.SendTo(buf, _ip, _port);  
	}
private:  
	UdpSocket _sock; 
	std::string _ip;  
	uint16_t _port;
};
