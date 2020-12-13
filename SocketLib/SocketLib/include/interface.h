#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <string>
#include "socket_info.h"

namespace network{

using Port = unsigned short;
using Address = std::string;
using Family = int;

//! interface
class ITcpSock {
public: 
	ITcpSock(){}
	virtual ~ITcpSock(){}

	virtual int Accept() = 0;
	virtual int Connect(const Address& address, const Port& port, const Family& family = AF_INET)const = 0;
	virtual int Bind()const = 0;
	virtual int Close()const = 0;
	virtual int Listen(int listen_time)const = 0;
	virtual int Recieve(char* buffer, int buffer_size)const = 0;
	virtual int Send(const char* buffer, int buffer_size)const = 0;
};

//! interface
class IUdpSock {
public:
	IUdpSock(){}
	virtual ~IUdpSock(){}

	virtual int Initialize(const Address& address, const Port& port, const Family& family) = 0;
	virtual int Finalize()const = 0;
	virtual int Bind()const = 0;
	virtual int Close()const = 0;
	virtual int Recieve(char* buffer)const = 0;
	virtual int Send(char* buffer)const = 0;
};
}

#endif //! INTERFACE_H_
