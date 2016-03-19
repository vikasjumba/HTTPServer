#include <stdio.h>
#include "HttpServer.h"
#include <iostream>
#include "HttpClient.h"

using namespace std;

int main(int argc, char **argv)
{
	if(argc == 1)
	{
		// sample code to create http server 
		HttpServer httpServer;
		int res = httpServer.startServer();
		if (res == -1)
		{
			return res;
		}
		
	}else if(argc == 3){
		// sample code to create http client
		string ip = argv[1];
		int port = stoi(string(argv[2]));
		HttpClient httpClient(ip, port);
		string response = httpClient.requestToHttpServer();
		cout << "Received string "<< response << endl; 
	}
	return 0;
}
