#ifndef SOCKET_INFO_H_
#define SOCKET_INFO_H_

#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib")

using MySockaddr = sockaddr_in;
using OppoSockAddr = sockaddr_in;

namespace network {
struct SocketInfo {
	WSADATA			wsadata;
	SOCKET			socket;
	SOCKET			opposock;
	MySockaddr		mysockaddr;
	OppoSockAddr opposockaddr;
};
}

#endif //! SOCKET_INFO_H_
