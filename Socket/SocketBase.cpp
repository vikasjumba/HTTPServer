#include "SocketBase.h"
#include <iostream>
using namespace std;

SocketBase::SocketBase() : sPort(9002), sDomain(AF_INET), sType(SOCK_STREAM), sProtocol(0), sIp("0.0.0.0")
{
// constructor with default values 
	createSocket();
}
SocketBase::SocketBase(int port, int domain, int type, int protocol, string ip): sPort(port), sDomain(domain), sType(type), sProtocol(protocol), sIp(ip)
{
// constructor with user given values 
	createSocket();
}
void SocketBase::createSocket()
{
// Create a socket
    sockDesc = socket(sDomain, sType, sProtocol);
	if (sockDesc == -1)
	{
		// error while creating socket
		cout << "Error in socket creation -> " << strerror(errno) << "\n";
	}
}
int SocketBase::start()
{
	// the base class virtual function only initialize the address structure of socket system library
	
	// the remaining functionalities such as connect (incase a client is implemented) or bind, listen and accept (in case of a server) are implemented in derived classes
    this->sockAddr.sin_family = sDomain;
    this->sockAddr.sin_port = htons(sPort); // convert the integer port to network format
	if (sIp == "0.0.0.0")
	{
	// system address
		this->sockAddr.sin_addr.s_addr = INADDR_ANY;
	}
	else
	{
	// address specified
		if(inet_aton(sIp.c_str(),(struct in_addr*)&(this->sockAddr.sin_addr.s_addr)) == 0)
		{
			cout << "Error in address conversion -> " << strerror(errno) << "\n";
			return -1;
		}
	}
	
	return 0;
}

int SocketBase::sendData(int destSockDesc, char* buff, size_t size, int flags)
{
	if(stream.write(destSockDesc, buff, size, flags) <= 0)
    {
        cout << "Error in sending data -> " << strerror(errno) << "\n";
        return -1;
    }
        cout << "Data send from server" << "\n";
    return 0;
}
int SocketBase::receiveData(int senderSockDesc, char* buff, size_t size, int flags)
{
	if(stream.read(senderSockDesc, buff, size, flags) <= 0)
    {
        cout << "Error in receiving data -> " << strerror(errno) << "\n";
        return -1;
    }
        cout << "Data received at server" << "\n";
    return 0;
}
SocketBase::~SocketBase()
{
	close(sockDesc);
}
