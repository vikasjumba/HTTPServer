#include "HttpServer.h"

HttpServer::HttpServer()
{	
	int port = 8080;
	int domain = AF_INET;
	int type = SOCK_STREAM;
	int protocol = 0;
	int backLog = 5;
	
	sockAccept = new SockAccept(port,domain, type, protocol, backLog);
	status = sockAccept->start();
	if(status == -1)
	{
		cout << "Server socket failure" << "\n";	
	}
}	
string HttpServer::parseHttpRequest(char* request)
{
	char *save, *token, *method, *fileInfo;
	string fileStr;
//	cout <<"request" << request << endl;
	token = strtok_r(request, "\r\n", &save); // only need to read first line	
	//cout <<"First line of request" << token << endl; 
	if (strlen(token) != 0 && token != nullptr)
	{
		char* refPtr;
		method = strtok_r(token, " ", &refPtr);
	//	cout <<"method" << method << endl; 
		fileInfo = strtok_r(NULL, " ", &refPtr);
	//	cout <<"fileInfo" << fileInfo << endl; 
	}

	if (strlen(fileInfo) <= 1 || fileInfo == NULL)
	{
		fileInfo = (char*)string("/index.html").c_str();
	}
		//cout << "fileName" << fileInfo << endl;
		//cout << "fileName" << ++fileInfo << endl;
		// parse the file into string
		string fileName(++fileInfo);  // discard the first character in string which is /
		ifstream file(fileName);
		stringstream strStream;
		strStream << file.rdbuf();//read the file
		fileStr = strStream.str();//fileStr holds the content of the file
	
	return fileStr;
}
string HttpServer::getResponse(string fileStr)
{
	string result = "HTTP/1.1 200 OK\r\n Content-Type: text/html\r\n Content-Length: ";
	result += to_string(fileStr.length()*sizeof(char)) + string("\r\n\n");
	result += fileStr;
	return result;
}
void HttpServer::handleClientRequest(int clientSd)
{	
	char request[buffSize];
	sockAccept->receiveData(clientSd,request,buffSize,0);
	//cout << "Received request " << request << "\n";
	string fileStr = parseHttpRequest(request); 
	//cout << "fileStr " << fileStr << "\n";
	string responseStr = getResponse(fileStr);
	//cout << "responseStr " << responseStr << "\n";
	size_t len = responseStr.length();
	sockAccept->sendData(clientSd,(char*)responseStr.c_str(),len,0);
}
int HttpServer::startServer()
{	
	if(status == -1)
	{
		return status;
	}	
	while(1)
	{
		int clientSd = sockAccept->acceptConnections();
		handleClientRequest(clientSd); // will launch in separate thread;
		close(clientSd);	
	}
}

HttpServer::~HttpServer()
{
	delete sockAccept;
}
