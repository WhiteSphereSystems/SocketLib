#ifndef SOCKET_INFO_H_
#define SOCKET_INFO_H_

#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib")

using MySockaddr = sockaddr_in;
using OpponentSockaddr = sockaddr_in;
using Size = int;

namespace network {
struct SocketInfo {
	WSADATA				wsadata;
	SOCKET				socket;
	MySockaddr			my_sockaddr;
	Size				my_sockaddr_size;
	OpponentSockaddr	oppnent_sockaddr;
	Size				oppnent_sockaddr_size;
};
}

#endif //! SOCKET_INFO_H_
