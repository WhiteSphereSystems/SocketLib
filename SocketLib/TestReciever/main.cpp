#include <iostream>
#include <memory>
#include <string>

#include "../SocketLib/include/udp.h"

struct TEST {
	int a;
	int b;
	int c;
};

int main() {

	std::unique_ptr<network::IUdpSock> sock = std::make_unique<network::UdpSock>("0.0.0.0", 50000, AF_INET);

	TEST test;
	char buffer[256] = {0};

	sock->Bind();

	while (1) {
		sock->Recieve(reinterpret_cast<char*>(&test), sizeof(test));
		if (test.a) {
			std::cout << std::string(std::to_string(test.a)) << std::endl;
		}
		//Sleep(100);
	}

	getchar();

	return 0;
}
