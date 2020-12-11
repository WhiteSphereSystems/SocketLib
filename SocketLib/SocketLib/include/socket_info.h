#ifndef SOCKET_INFO_H_
#define SOCKET_INFO_H_

#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib")

namespace network {

using MySockaddr = sockaddr_in;
using OpponentSockaddr = sockaddr_in;
using Size = int;

struct SocketInfo {
	WSADATA				wsadata;
	SOCKET				socket;
	MySockaddr			my_sockaddr;
	Size				my_sockaddr_size;
	OpponentSockaddr	opponent_sockaddr;
	Size				opponent_sockaddr_size;
};
}

#endif //! SOCKET_INFO_H_
