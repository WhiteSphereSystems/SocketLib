#include "TCPSock.h"

namespace Network {

	TcpSock::TcpSock(int port, int address, int family) : ITcpSock(port, address, family) {

	};

	int TcpSock::Initialize(int port, int address, int family) {

	}

	int TcpSock::Bind() {

	}

	int TcpSock::Listen() {

	}

	int TcpSock::Accept() {

	}

	int TcpSock::Send(void* buffer) {

	}

	int TcpSock::Recieve(void* buffer) {

	}

	int TcpSock::Close() {

	}

	int TcpSock::Finalize() {

	}
}