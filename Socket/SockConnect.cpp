#include "SockConnect.h"
#include <iostream>

using namespace std;
SockConnect::SockConnect()
{
// super class calls socket	
}
SockConnect::SockConnect(int port, int domain, int type, int protocol, string ip) : SocketBase(port, domain, type, protocol, ip)
{
// super class calls socket	
}
int SockConnect::start()
{
	int status = SocketBase::start();   // initialize the socket address
	if (status == -1)
	{
		// error printed in base class
		return status;
	}
	// proceed with connect
	if (connect(sockDesc, (struct sockaddr *)&(this->sockAddr), sizeof(this->sockAddr)) != 0)
    {
        cout << "Error in connection -> " << strerror(errno) << "\n";
        return -1;
    }
    return 0;
}

SockConnect::~SockConnect()
{
    // base class closes socket;
}

