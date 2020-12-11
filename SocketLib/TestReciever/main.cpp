#include <iostream>
#include <memory>
#include <string>

#include "../SocketLib/include/udp.h"

int main() {

	std::unique_ptr<network::IUdpSock> sock = std::make_unique<network::UdpSock>("127.0.0.1", 50000, AF_INET);

	char* buffer = nullptr;

	sock->Bind();

	while (1) {
		sock->Recieve(buffer);
		if (buffer) {
			std::cout << std::string(buffer) << std::endl;
		}
		//Sleep(100);
	}

	return 0;
}
