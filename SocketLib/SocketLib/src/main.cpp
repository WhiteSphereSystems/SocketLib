#include "../include/TCPSock.h"

#include <iostream>
#include <memory>
#include <string>



int main() {

	//network::ITcpSock *sock = &network::TcpSock("127.0.0.1", 12345, AF_INET);
	std::unique_ptr<network::ITcpSock> sock = std::make_unique<network::TcpSock>("127.0.0.1", 12345, AF_INET);
	char buffer[32];

	memset(&buffer, 0, sizeof(buffer));

	sock->Connect();

	sock->Recieve(buffer);

		std::cout << buffer << std::endl;
	

	sock->Close();
}