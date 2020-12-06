#ifndef SOCKETINFO_H
#define SOCKETINFO_H

#include <WinSock2.h>

struct SocketInfo {
	WSADATA wsa_data;
	SOCKET m_sock;
	struct sockaddr_in m_mine;
	struct sockaddr_in m_oppnent;
};

#endif // !SOCKETINFO_H

