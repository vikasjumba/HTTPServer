#ifndef SOCKBASE_H
#define SOCKBASE_H

#include "SockIncludes.h"
#include "SockStream.h"
#include <string>

/*
This is a base class for creating client server model.
	It create sockets, 
	send and receive data, 
	partial or common functionality to start the server or client socket connection
	contains an object of socket stream to stream data i.e. send and receive data over established connection

The class is inherited to create server and client functionalities
   
*/

using namespace std;

class SocketBase
{
private:
   	int sPort;
	int sDomain;
	int sType;
	int sProtocol;
	string sIp;
public:
	struct sockaddr_in sockAddr;
	SockStream stream;
	int sockDesc;
    SocketBase();
	SocketBase(int port, int domain, int type, int protocol, string ip);
	void createSocket();
	virtual int start();
	int sendData(int sockDesc, char* buff, size_t size, int flags);
    int receiveData(int sockDesc, char* buff, size_t size, int flags);
	
 //   int initAcceptingConnections(int port, int domain, int type, int protocol);
 //   int startAcceptingConnections(int backLog);
    
    //int getSockDesc();
    virtual ~SocketBase();

};

#endif // SOCKBASE_H
