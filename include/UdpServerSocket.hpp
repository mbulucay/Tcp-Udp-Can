#ifndef UDP_SERVER_SOCKET_HPP_
#define UDP_SERVER_SOCKET_HPP_

#include <Socket.hpp>
#include <string>

class UDPServerSocket : public Socket
{
    private:
    /* data */
    public:
        UDPServerSocket(std::string ip, uint32_t port);
        ~UDPServerSocket();

        SocketType getSocketType() { return SocketType::UDPServer; }

};

#endif // !UDP_SERVER_SOCKET_HPP_