#include <iostream>
#include <memory>
#include <string>
#include <tchar.h>

#include "../SocketLib/include/udp.h"

int main() {

	std::unique_ptr<network::IUdpSock> sock = std::make_unique<network::UdpSock>("127.0.0.1", 50000, AF_INET);
	char message[256];
	memset(message, 0, sizeof(message));

	std::cin >> message;
	OutputDebugStringA(message);
	OutputDebugStringA("\n");

	sock->Send("127.0.0.1", 50000, message, strlen(message));

	getchar();

	return 0;
}
