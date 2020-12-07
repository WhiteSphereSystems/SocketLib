#include "TCPSock.h"

namespace network{


int TcpSock::Initialize(const Address& address, const Port& port, const Family& family)const {
	WSAStartup(MAKEWORD(2, 0), &this->m_socket_info->wsadata);

	memset(&this->m_socket_info->mysockaddr, 0, sizeof(MySockaddr));

	this->InitSocket(address, port, family);

	this->m_socket_info->socket = socket(family, SOCK_STREAM, 0);

	return 0;

}

int TcpSock::InitSocket(const Address& address, const Port& port, const Family& family)const {

	this->m_socket_info->mysockaddr.sin_port = htons(port);
	this->m_socket_info->mysockaddr.sin_family = family;
	inet_pton(this->m_socket_info->mysockaddr.sin_family,address.c_str(),&this->m_socket_info->mysockaddr.sin_addr.S_un.S_addr);

	return 0;

}

int TcpSock::Bind()const {

	bind(this->m_socket_info->socket, (struct sockaddr*)&this->m_socket_info->mysockaddr, sizeof(this->m_socket_info->mysockaddr));

	return 0;

}

int TcpSock::Listen(int listen_time)const {

	listen(this->m_socket_info->socket, listen_time);

	return 0;

}

int TcpSock::Accept() {

	this->oppnent_len = sizeof(this->m_oppnent);

	this->m_oppnent_sock.reset((SOCKET*)accept(this->m_socket_info->socket, (struct sockaddr*)&this->m_oppnent, &this->oppnent_len));

	if (this->m_socket_info->socket == INVALID_SOCKET) {
		printf("accept : %d\n", WSAGetLastError());
		return 1;
	}
	return 0;

}

int TcpSock::Send(char* buffer)const {

	send(this->m_socket_info->socket, buffer, sizeof(buffer), 0);

	return 0;

}

int TcpSock::Recieve(char* buffer)const {

	memset(buffer, 0, sizeof(buffer));

	recv(this->m_socket_info->socket, buffer, sizeof(buffer), 0);

	return 0;

}

int TcpSock::Close()const {

	closesocket(this->m_socket_info->socket);

	return 0;

}

int TcpSock::Finalize()const {

	Close();

	WSACleanup();

	return 0;

}
}