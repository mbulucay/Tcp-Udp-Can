#ifndef UDP_CLIENT_SOCKET_HPP_
#define UDP_CLIENT_SOCKET_HPP_

#include <Socket.hpp>
#include <string>

class UDPClientSocket : public Socket
{
    private:
        /* data */
    public:
        UDPClientSocket(std::string ip, uint32_t port);
        ~UDPClientSocket();

        void send(std::string message);

        SocketType getSocketType() { return SocketType::UDPClient; }

};

#endif // !UDP_CLIENT_SOCKET_HPP_
