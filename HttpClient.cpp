/*
GET /hello.html HTTP/1.0\r\n
Host: 127.0.0.1:8000\r\n
Connection: keep-alive\r\n
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*//*;q=0.8\r\n
User-Agent: Chrome/45.0.2454.93\r\n
Accept-Encoding: gzip,deflate,sdch\r\n
Accept-Language: en-US,en;q=0.8\r\n
\r\n
*/
#include "HttpClient.h"

HttpClient::HttpClient()
{
	// Default constructor assume running http server at local machine and hence connect with it
	int port = 8080;
	int domain = AF_INET;
	int type = SOCK_STREAM;
	int protocol = 0;
	
	sockConnect = new SockConnect(port,domain, type, protocol);
	int status = sockConnect->start();
	if(status == -1)
	{
		cout << "HTTP client socket failure" << "\n";	
	}
}
HttpClient::HttpClient(string ip, int port)
{
	// Takes in ip and port of http server and connect with it
	int domain = AF_INET;
	int type = SOCK_STREAM;
	int protocol = 0;
	
	sockConnect = new SockConnect(port,domain, type, protocol, ip);
	int status = sockConnect->start();
	if(status == -1)
	{
		cout << "HTTP client socket failure" << "\n";	
	}
}
string HttpClient::requestToHttpServer(string method, string file)
{
	string httpHeader = method + string(" ") + string(file) + string(" HTTP/1.1\r\n\n");	
	cout << httpHeader << endl;
	if(sockConnect->sendData(sockConnect->sockDesc, (char*)httpHeader.c_str(),httpHeader.length(),0) == -1)
	{
		cout << "HTTP client socket request failure" << "\n";	
		return "-1";	
	}
	char httpResponse[buffSize];
	if(sockConnect->receiveData(sockConnect->sockDesc,httpResponse,buffSize,0) == -1)
	{
		cout << "HTTP client socket response failure" << "\n";	
		return "-1";	
	}
	
	return string(httpResponse);
	
}	

HttpClient::~HttpClient()
{
	delete (sockConnect);
}
