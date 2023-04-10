#include <SocketFactory.hpp>
#include <Socket.hpp>

#include <UdpServerSocket.hpp>
#include <UdpClientSocket.hpp>

#include <TcpServerSocket.hpp>
#include <TcpClientSocket.hpp>

#include <CanServerSocket.hpp>
#include <CanClientSocket.hpp>


SocketFactory::SocketFactory(const std::string& ip, uint32_t port = 5871)
    : m_ip(ip), m_port(port)
{}

SocketFactory::~SocketFactory()
{}

Socket* SocketFactory::createSocket(const SocketType type) const {

    Socket* socket = nullptr;

    switch (type)
    {
        case SocketType::UDPServer: socket = new UDPServerSocket(m_ip, m_port);
            break;
        case SocketType::UDPClient: socket = new UDPClientSocket(m_ip, m_port);
            break;
        case SocketType::TCPServer: socket = new TCPServerSocket(m_ip, m_port);
            break;
        case SocketType::TCPClient: socket = new TCPClientSocket(m_ip, m_port);
            break;
        case SocketType::CANServer: socket = new CANServerSocket(m_ip);
            break;
        case SocketType::CANClient: socket = new CANClientSocket(m_ip);
            break;
    }

    return socket;
}
