#include "SockStream.h"

SockStream::SockStream()
{
}
ssize_t SockStream::read(int sockDesc, char* buff, size_t size, int flags)
{
    ssize_t byteCount = recv(sockDesc, buff, size, flags);
    return byteCount;
}
ssize_t SockStream::write(int sockDesc, char* buff, size_t size, int flags)
{
    ssize_t byteCount = send(sockDesc, buff, size, flags);
    return byteCount;
}
SockStream::~SockStream()
{
}

