#ifndef SOCKET_FACTORY_HPP_
#define SOCKET_FACTORY_HPP_

#include <Socket.hpp>
#include <string>

class SocketFactory
{
    private:
        std::string m_ip;
        uint32_t m_port;

    public:
        SocketFactory(const std::string& ip) : m_ip(ip){}
        SocketFactory(const std::string& ip, uint32_t port);
        Socket* createSocket(const SocketType type) const ;
        ~SocketFactory();
};


#endif // !SOCKET_FACTORY_HPP_