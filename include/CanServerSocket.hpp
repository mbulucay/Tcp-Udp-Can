#ifndef CAN_SERVER_SOCKET_HPP_
#define CAN_SERVER_SOCKET_HPP_


#include <iostream>
#include <Socket.hpp>
#include <string>
#include <cstring>
#include <linux/can/j1939.h>
#include <net/if.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>


class CANServerSocket : public Socket
{
private:
    struct sockaddr_can m_can_addr;
	struct ifreq m_ifr;
    int m_filter_msg;

public:
    CANServerSocket(const std::string &can_addr_str);
    ~CANServerSocket();

    SocketType getSocketType() { return SocketType::CANServer; }
    sockaddr_can *getSockAddr() { return &m_can_addr; }
};

#endif // !TCP_SERVER_SOCKET_HPP_
