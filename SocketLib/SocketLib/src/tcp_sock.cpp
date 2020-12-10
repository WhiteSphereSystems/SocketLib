#include"../include/tcp_sock.h"

namespace network{


int TcpSock::Initialize(const Address& address, const Port& port, const Family& family)const {
	WSAStartup(MAKEWORD(2, 0), &this->m_socket_info->wsadata);

	memset(&this->m_socket_info->mysockaddr, 0, sizeof(this->m_socket_info->mysockaddr));
	this->InitSocket(address, port, family);

	this->m_socket_info->socket = socket(family, SOCK_STREAM, 0);


	return 0;

}

int TcpSock::InitSocket(const Address& address, const Port& port, const Family& family)const {

	this->m_socket_info->mysockaddr.sin_family = family;
	this->m_socket_info->mysockaddr.sin_port = htons(port);
	inet_pton(this->m_socket_info->mysockaddr.sin_family,address.c_str(),&this->m_socket_info->mysockaddr.sin_addr.S_un.S_addr);

	return 0;

}

int TcpSock::Bind()const {

	bind(this->m_socket_info->socket, reinterpret_cast<struct sockaddr*>(&this->m_socket_info->mysockaddr), sizeof(this->m_socket_info->mysockaddr));

	return 0;

}

int TcpSock::Listen(int listen_time)const {

	listen(this->m_socket_info->socket, listen_time);

	return 0;

}

int TcpSock::Accept() {

	this->opponent_addr_len = sizeof(this->m_socket_info->opposockaddr);

	this->m_socket_info->opposock = accept(this->m_socket_info->socket, reinterpret_cast<struct sockaddr*>(&this->m_socket_info->opposockaddr), reinterpret_cast<int*>(&this->opponent_addr_len));

	if (this->m_socket_info->socket == INVALID_SOCKET) {
		printf("accept : %d\n", WSAGetLastError());
		return 1;
	}
	return 0;

}

int TcpSock::Connect()const {

	connect(m_socket_info->socket, reinterpret_cast<struct sockaddr*>(&m_socket_info->opposockaddr), sizeof(m_socket_info->opposockaddr));

	return 0;

}

int TcpSock::Send(const char* buffer)const {

	send(this->m_socket_info->socket, buffer, sizeof(buffer), 0);

	return 0;

}

int TcpSock::Recieve(const char *buffer)const {

	recv(this->m_socket_info->socket, const_cast<char *>(buffer), sizeof(buffer), 0);

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