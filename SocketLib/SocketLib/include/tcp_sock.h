#ifndef TCP_H
#define TCP_H

#include <memory>
#include <WS2tcpip.h>

#include "interface.h"


namespace network{
class TcpSock : public ITcpSock {
public:

	TcpSock(const Address& address, const Port& port, const Family& family):m_socket_info(new SocketInfo) {
		Initialize(address, port, family);
	};

	~TcpSock() {
		Finalize();
	};
	
	virtual int Accept()override;
	virtual int Connect(const Address& address, const Port& port, const Family& family = AF_INET)const override;
	virtual int Bind()const override;
	virtual int Close()const override;
	virtual int Listen(int listen_time_second)const override;
	virtual int Recieve(char* buffer, int buffer_size)const override;
	virtual int Send(const char* buffer, int buffer_size)const override;
private:
	std::unique_ptr<SocketInfo> m_socket_info;

	unsigned int opponent_addr_len;

	int Initialize(const Address& address, const Port& port, const Family& family)const;
	int InitSocket(const Address& address, const Port& port, const Family& family)const;
	int Finalize()const;

};

}
#endif // !TCP_H
