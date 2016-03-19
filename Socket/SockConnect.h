#ifndef SOCKCONNECT_H
#define SOCKCONNECT_H

#include "SocketBase.h"
#include <string>
/*
This class creates a client object by inheriting the functionalities of base socket class "SocketBase"
SockConnect(int port, int domain, int type, int protocol, string ip) -> instantiate the object and create the socket
int start() -> connect the socket to the server
*/
using namespace std;
class SockConnect : public SocketBase
{
public:
    SockConnect();
	SockConnect(int port, int domain, int type, int protocol, string ip = "0.0.0.0");
	int start();
    ~SockConnect();
};

#endif // SOCKCONNECT_H
