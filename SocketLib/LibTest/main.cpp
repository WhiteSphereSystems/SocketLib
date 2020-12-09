#include <iostream>
#include <memory>
#include <string>

#include "../SocketLib/include/udp.h"

int main() {

	std::unique_ptr<network::IUdpSock> sock = std::make_unique<network::UdpSock>("127.0.0.1", 50000, AF_INET);
	void* recieve = nullptr;

	sock->Bind();

	while (1) {
		sock->Recieve(reinterpret_cast<char*>(recieve));
	}

	std::cout << recieve << std::endl;;

	sock->Close();

	return 0;
}
