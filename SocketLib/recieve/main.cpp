#include <iostream>
#include <stdio.h>
#include <string.h>

#include "../SocketLib/include/tcp_sock.h"

struct SendData {
	int a = 0;
	char b[12];
	long c = 0;
};

int main()
{

	//WSADATA wsaData;
	//struct sockaddr_in server;
	//SOCKET sock;
	//char buf[32];
	////SendData data;

	//// winsock2�̏�����
	//WSAStartup(MAKEWORD(2, 0), &wsaData);

	//// �\�P�b�g�̍쐬
	//sock = socket(AF_INET, SOCK_STREAM, 0);

	//// �ڑ���w��p�\���̂̏���
	//server.sin_family = AF_INET;
	//server.sin_port = htons(12345);
	//server.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	//// �T�[�o�ɐڑ�
	//connect(sock, (struct sockaddr*)&server, sizeof(server));

	//// �T�[�o����f�[�^����M
	//memset(buf, 0, sizeof(buf));


	////int n = recv(sock, (char*)&data, sizeof(data), 0);
	//int n = recv(sock, buf, sizeof(buf), 0);


	//printf("%s", buf);

	///*printf("%d, %d\n", data.a, data.c);
	//printf("%s", data.b);*/

	//// winsock2�̏I������
	//WSACleanup();

	//return 0;

	std::unique_ptr<network::ITcpSock> sock = std::make_unique<network::TcpSock>("https://www.google.com/?hl=ja", 12345, AF_INET);
	char buffer[32];
	
	memset(&buffer, 0, sizeof(buffer));

	sock->Connect("https://www.google.com/?hl=ja", 12345, AF_INET);

	sock->Recieve(buffer,sizeof(buffer));

	std::cout << buffer << std::endl;

	return 0;
}
