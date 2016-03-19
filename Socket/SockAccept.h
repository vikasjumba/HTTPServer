#ifndef SOCKACCEPT_H
#define SOCKACCEPT_H
#include "SocketBase.h"
/*
This creates a server with active socket connection
SockAccept() -> Creates a socket connection with default values
SockAccept(int port, int domain, int type, int protocol, int backLog, string ip) -> creates a socket connection with specified values;
int start() -> activate server from binding to listen and accept state.
*/
class SockAccept : public SocketBase
{
public:
	int sBackLog;
    SockAccept();
	SockAccept(int port, int domain, int type, int protocol, int backLog, string ip = "0.0.0.0");
	int start();  
	int acceptConnections(struct sockaddr_in* clientInfo = nullptr); 
    ~SockAccept();

};

#endif // SOCKACCEPT_H
