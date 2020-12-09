#ifndef UDP_H_
#define UDP_H_

#include <memory>
#include <WS2tcpip.h>

#include "interface.h"
#include "socket_info.h"

namespace network{

class UdpSock final: public IUdpSock {
public:	
	UdpSock(const Address& address, const Port& port, const Family& family):socket_info(new SocketInfo()){
		Initialize(address, port, family);
	};
	~UdpSock(){
		Finalize();
	};

	int Initialize(const Address& address, const Port& port, const Family& family)override;
	int Finalize()const override;
	int Bind()const override;
	int Close()const override;
	int Recieve(char* buffer)const override;
	int Send(const char* buffer)const override;
private:
	std::unique_ptr<SocketInfo> socket_info;

	int InitSocket(const Address& address, const Port& port, const Family& family)const;
};
}

#endif //! UDP_H_
