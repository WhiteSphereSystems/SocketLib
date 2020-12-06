#ifndef TCP_H
#define TCP_H

#include "interface.h"
namespace Network {
	class TcpSock : public Network::ITcpSock {
	public:

		//TcpSock(int port, int address, int family) : ITcpSock(port, address, family) {};
		TcpSock(int port, int address, int family);
		~TcpSock();

		virtual int Initialize(int port, int address, int family);
		virtual int Finalize();
		virtual int Accept();
		virtual int Bind();
		virtual int Close();
		virtual int Listen();
		virtual int Recieve(void* buffer);
		virtual int Send(void* buffer);
	};

}
#endif // !TCP_H
