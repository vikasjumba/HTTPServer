#ifndef SOCKSTREAM_H
#define SOCKSTREAM_H

#include "SockIncludes.h"
/*
This class provides streaming functionalities for connected socket
	Read data
	Write data
*/
class SockStream
{
private:    
public:
	ssize_t read(int sockDesc, char* buff, size_t size, int flags);
    ssize_t write(int sockDesc, char* buff, size_t size, int flags);
    SockStream();
    ~SockStream();
};

#endif // SOCKSTREAM_H
