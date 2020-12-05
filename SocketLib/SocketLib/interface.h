#ifndef INTERFACE_H_
#define INTERFACE_H_

namespace Network{

//! interface
class ITcpSock {
public: 
	ITcpSock(int port, int address, int family){
		Initialize(port, address, family);
	};

	virtual ~ITcpSock(){
		Finalize();
	};

	virtual int Initialize(int port, int address, int family) = 0;
	virtual int Finalize() = 0;
	virtual int Accept() = 0;
	virtual int Bind() = 0;
	virtual int Close() = 0;
	virtual int Listen() = 0;
	virtual int Recieve(void* buffer) = 0;
	virtual int Send(void* buffer) = 0;
};

//! interface
class IUdpSock {
public:
	IUdpSock(int port, int address, int family){
		Initialize(port, address, family);
	};

	virtual ~IUdpSock(){
		Finalize();
	};

	virtual int Initialize(int port, int address, int family) = 0;
	virtual int Finalize() = 0;
	virtual int Bind() = 0;
	virtual int Close() = 0;
	virtual int Recieve(void* buffer) = 0;
	virtual int Send(void* buffer) = 0;
};
}

#endif //! INTERFACE_H_
