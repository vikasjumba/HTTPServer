#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include "Socket/SockAccept.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
class HttpServer{

private:
	const int buffSize = 2048; 
	SockAccept *sockAccept;
	string parseHttpRequest(char* request);
	string getResponse(string fileStr);
	void handleClientRequest(int clientSd);
public:
	int status;
	HttpServer();
	int startServer();	
	~HttpServer();
};

#endif
