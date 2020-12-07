#ifndef TCP_H
#define TCP_H

#include <memory>
#include <WS2tcpip.h>

#include "include/interface.h"
#include "include/socket_info.h"

namespace network{
class TcpSock : public ITcpSock {
public:

	TcpSock(const Address& address, const Port& port, const Family& family) {
		Initialize(address, port, family);
	};

	~TcpSock() {
		Finalize();
	};

	virtual int Initialize(const Address& address, const Port& port, const Family& family)const override;
	virtual int Finalize()const override;
	virtual int Accept()override;
	virtual int Bind()const override;
	virtual int Close()const override;
	virtual int Listen(int listen_time)const override;
	virtual int Recieve(char* buffer)const override;
	virtual int Send(char* buffer)const override;
private:
	std::unique_ptr<SocketInfo> m_socket_info;
	std::unique_ptr<sockaddr_in> m_oppnent;
	std::unique_ptr<SOCKET> m_oppnent_sock;
	int oppnent_len;

	int InitSocket(const Address& address, const Port& port, const Family& family)const;
};

}
#endif // !TCP_H
