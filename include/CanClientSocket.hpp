#ifndef CAN_CLIENT_SOCKET_HPP_
#define CAN_CLIENT_SOCKET_HPP_

#include <Socket.hpp>
#include <string>

class CANClientSocket : public Socket
{
    private:
        std::string m_can_name;
    public:
        CANClientSocket(const std::string& can_name);
        ~CANClientSocket();

        SocketType getSocketType() { return SocketType::CANClient; }

};

#endif // !CAN_CLIENT_SOCKET_HPP_