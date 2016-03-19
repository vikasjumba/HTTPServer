#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include "Socket/SockConnect.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
class HttpClient{

private:
	const int buffSize = 2048; 
	SockConnect *sockConnect;
	//string sendHttpRequest(char* request);
public:
	HttpClient();
	HttpClient(string ip, int port);
	string requestToHttpServer(string method = "GET", string file = "/");	
	~HttpClient();
};

#endif
