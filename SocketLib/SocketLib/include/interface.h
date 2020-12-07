#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <string>

namespace network{

using Port = unsigned short;
using Address = std::string;
using Family = int;

//! interface
class ITcpSock {
public: 
	ITcpSock(){}
	virtual ~ITcpSock(){}

	virtual int Initialize(const Address& address, const Port& port, const Family& family)const = 0;
	virtual int Finalize()const = 0;
	virtual int Accept() = 0;
	virtual int Bind()const = 0;
	virtual int Close()const = 0;
	virtual int Listen(int listen_time)const = 0;
	virtual int Recieve(char* buffer)const = 0;
	virtual int Send(char* buffer)const = 0;
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
