#include <iostream>
#include <memory>
#include <string>

#include "../SocketLib/include/udp.h"

int main() {

	std::unique_ptr<network::IUdpSock> sock = std::make_unique<network::UdpSock>("0.0.0.0", 50000, AF_INET);

	char buffer[256] = {0};

	sock->Bind();

	while (1) {
		sock->Recieve(buffer, sizeof(buffer));
		if (buffer) {
			std::cout << std::string(buffer) << std::endl;
		}
		//Sleep(100);
	}

	return 0;
}
