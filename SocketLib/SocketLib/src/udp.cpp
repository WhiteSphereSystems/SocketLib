#include "../include/udp.h"

namespace network {
int UdpSock::Initialize(const Address& address, const Port& port, const Family& family = AF_INET) {
	this->socket_info->my_sockaddr_size = sizeof(this->socket_info->my_sockaddr);
	this->socket_info->oppnent_sockaddr_size = sizeof(this->socket_info->oppnent_sockaddr);

	WSAStartup(MAKEWORD(2,0), &this->socket_info->wsadata);

	memset(&this->socket_info->my_sockaddr, 0, sizeof(this->socket_info->my_sockaddr));
	//Initialize Send Socket
	this->InitSocket(address, port, family);

	//CreateSocket
	this->socket_info->socket = socket(family, SOCK_DGRAM, 0);
	return 0;
}

int UdpSock::Finalize()const {
	Close();
	WSACleanup();
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
	return 0;
}

int UdpSock::Recieve(char* buffer)const {
	recvfrom(this->socket_info->socket,
	buffer,
	sizeof(*buffer),
	0,
	reinterpret_cast<sockaddr*>(&this->socket_info->oppnent_sockaddr),
	&this->socket_info->oppnent_sockaddr_size);
	return 0;
}

int UdpSock::Send(const char* buffer)const {
	sendto(this->socket_info->socket,
	buffer,
	sizeof(*buffer),
	0,
	reinterpret_cast<sockaddr*>(&this->socket_info->oppnent_sockaddr),
	this->socket_info->oppnent_sockaddr_size);
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
}
