#ifndef SOCKET_INFO_H_
#define SOCKET_INFO_H_

#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib")

using MySockaddr = sockaddr_in;

namespace network {
struct SocketInfo {
	WSADATA			wsadata;
	SOCKET			socket;
	MySockaddr		mysockaddr;
};
}

#endif //! SOCKET_INFO_H_
