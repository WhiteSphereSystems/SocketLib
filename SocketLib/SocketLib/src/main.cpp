#include "../include/tcp_sock.h"

#include <iostream>
#include <memory>
#include <string>



int main() {
	//óM‘¤
	/*
	std::unique_ptr<network::ITcpSock> sock = std::make_unique<network::TcpSock>("127.0.0.1", 12345, AF_INET);
	char buffer[32];

	memset(&buffer, 0, sizeof(buffer));
	
	sock->Connect();

	sock->Recieve(buffer);

	std::cout << buffer << std::endl;
	*/

	//‘—M‘¤
	std::unique_ptr<network::ITcpSock> sock = std::make_unique<network::TcpSock>("0.0.0.0", 12345, AF_INET);
	char buffer[32] = { "abcde" };
	int time = 5;


	sock->Bind();

	sock->Listen(time);

	sock->Accept();

	sock->Send(buffer);

	sock->Close();
}