#include <iostream>
#include <memory>
#include <string>

#include "../SocketLib/include/udp.h"

int main() {

	std::unique_ptr<network::IUdpSock> sock = std::make_unique<network::UdpSock>("0.0.0.0", 50000, AF_INET);
	void* recive = nullptr;

	sock->Bind();

	while (sock->Recieve(reinterpret_cast<char*>(recive)) > -1) {
		
	}

	std::cout << recive << std::endl;;

	sock->Close();

	return 0;
}
