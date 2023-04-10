#ifndef TCP_CLIENT_SOCKET_HPP_
#define TCP_CLIENT_SOCKET_HPP_

#include <Socket.hpp>
#include <string>

class TCPClientSocket : public Socket
{
    private:
        int client;
    public:
        TCPClientSocket(std::string ip, uint32_t port);
        ~TCPClientSocket();

        SocketType getSocketType() { return SocketType::TCPClient; }
};

#endif // !TCP_CLIENT_SOCKET_HPP_