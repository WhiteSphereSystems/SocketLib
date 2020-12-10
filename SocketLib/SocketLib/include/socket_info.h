#ifndef SOCKET_INFO_H_
#define SOCKET_INFO_H_

#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib")

using MySockaddr = sockaddr_in;
using OpponentSockAddr = sockaddr_in;

namespace network {
struct SocketInfo {
	WSADATA			wsadata;
	SOCKET			socket;
	SOCKET			opponentsock;
	MySockaddr		mysockaddr;
	OpponentSockAddr opponentsockaddr;
};
}

#endif //! SOCKET_INFO_H_
