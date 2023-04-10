#ifndef SOCKET_HPP_
#define SOCKET_HPP_

#include <netinet/in.h>

enum class SocketType {
    UDPServer, UDPClient, TCPServer, TCPClient, CANServer, CANClient
};

class Socket
{
protected:
    
    int m_sockfd;
    sockaddr_in m_servaddr;

public:
    Socket();
    virtual ~Socket();

    virtual SocketType getSocketType() = 0;
    
    int getSocketDescripter() { return m_sockfd; }
    sockaddr_in* getSockAddr() { return &m_servaddr; }
};

#endif // !SOCKET_HPP_