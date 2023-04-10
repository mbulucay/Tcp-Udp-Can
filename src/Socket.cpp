#include <Socket.hpp>
#include <unistd.h>
#include <cstring>

Socket::Socket()
{
    m_sockfd = -1;
    bzero(&m_servaddr, sizeof(sockaddr_in));
}

Socket::~Socket()
{
    close(m_sockfd);
}

