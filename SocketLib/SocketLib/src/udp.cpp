#include "../include/udp.h"

#ifdef _DEBUG
#include <iostream>
#include <string>
#endif

namespace network {
int UdpSock::Initialize(const Address& address, const Port& port, const Family& family)const {
	this->socket_info->my_sockaddr_size = sizeof(this->socket_info->my_sockaddr);
	this->socket_info->opponent_sockaddr_size = sizeof(this->socket_info->opponent_sockaddr);

	if (!WSAStartup(MAKEWORD(2, 0), &this->socket_info->wsadata)) return -1;

	memset(&this->socket_info->my_sockaddr, 0, sizeof(this->socket_info->my_sockaddr));
	//Initialize Send Socket
	this->InitSocket(address, port, family);

	//CreateSocket
	this->socket_info->socket = socket(family, SOCK_DGRAM, 0);
	return 0;
}

int UdpSock::Finalize()const {
	Close();
	return 0;
}

int UdpSock::Bind()const {
	bind(this->socket_info->socket,
	reinterpret_cast<sockaddr*>(&this->socket_info->my_sockaddr),
	sizeof(this->socket_info->my_sockaddr));
	return 0;
}

int UdpSock::Close()const {
	closesocket(this->socket_info->socket);
	WSACleanup();
	return 0;
}

int UdpSock::Recieve(char* buffer, int buffer_len)const {
	int debug = recvfrom(this->socket_info->socket,
	buffer,
	buffer_len,
	0,
	reinterpret_cast<sockaddr*>(&this->socket_info->opponent_sockaddr),
	&this->socket_info->opponent_sockaddr_size);

	if (debug == INVALID_SOCKET) {
		std::cout << "ERROR:" + std::to_string(WSAGetLastError()) << std::endl;
		return -1;
	}

	if (debug != SOCKET_ERROR) {
		return 1;
	}

	return 0;
}

int UdpSock::Send(const Address& address, const Port& port, const char* buffer, const int& buffer_len, const Family& family)const {
	//送信先情報の作成
	SetOpponentInfo(address, port, family);

	int debug = sendto(this->socket_info->socket,
		buffer,
		buffer_len,
		0,
		reinterpret_cast<sockaddr*>(&this->socket_info->opponent_sockaddr),
		this->socket_info->opponent_sockaddr_size);

	if (debug == INVALID_SOCKET) {
		std::cout << "ERROR:" + std::to_string(WSAGetLastError()) << std::endl;
	}
	return 0;
}

int UdpSock::InitSocket(const Address& address, const Port& port, const Family& family)const {
	this->socket_info->my_sockaddr.sin_port = htons(port);
	this->socket_info->my_sockaddr.sin_family = family;
	inet_pton(this->socket_info->my_sockaddr.sin_family,
	address.c_str(),
	&this->socket_info->my_sockaddr.sin_addr.S_un.S_addr);

	return 0;
}

int UdpSock::SetOpponentInfo(const Address& address, const Port& port, const Family& family)const {
	this->socket_info->opponent_sockaddr.sin_port = htons(port);
	this->socket_info->opponent_sockaddr.sin_family = family;
	inet_pton(this->socket_info->opponent_sockaddr.sin_family,
		address.c_str(),
		&this->socket_info->opponent_sockaddr.sin_addr.S_un.S_addr);
	return 0;
}
}
