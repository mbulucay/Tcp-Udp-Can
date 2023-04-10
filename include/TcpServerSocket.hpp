#ifndef TCP_SERVER_SOCKET_HPP_
#define TCP_SERVER_SOCKET_HPP_

#include <Socket.hpp>
#include <string>

class TCPServerSocket : public Socket
{
private:
    /* data */
public:
    TCPServerSocket(std::string ip, uint32_t port, uint32_t backlog = 10);
    ~TCPServerSocket();

    SocketType getSocketType() { return SocketType::TCPServer; }

};


#endif // !TCP_SERVER_SOCKET_HPP_
