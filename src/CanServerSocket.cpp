#include <CanServerSocket.hpp>
#include <iostream>
#include <arpa/inet.h>
#include <linux/can/j1939.h>
#include <sys/socket.h>

CANServerSocket::CANServerSocket(const std::string &can_addr_str)
{

    m_sockfd = socket(PF_CAN, SOCK_DGRAM, CAN_J1939);
    if (m_sockfd < 0)
    {
        std::cerr << "Can socket creation failed :" << __LINE__ << std::endl;
        exit(1);
    }
    m_filter_msg = 1;
    if (setsockopt(m_sockfd, SOL_CAN_J1939, SO_J1939_PROMISC, &m_filter_msg, sizeof(m_filter_msg)) < 0)
    {
        std::cerr << "Socket option setting failed :" << __LINE__ << std::endl;
        exit(1);
    }

    strcpy(m_ifr.ifr_name, can_addr_str.c_str());
    ioctl(m_sockfd, SIOCGIFINDEX, &m_ifr);

    m_can_addr.can_family = AF_CAN;
    m_can_addr.can_ifindex = m_ifr.ifr_ifindex;

    int ret = bind(m_sockfd, (struct sockaddr *)&m_can_addr, sizeof(m_can_addr));
    if (ret < 0)
    {
        std::cerr << "Socket bind failed :" << ret << __FILE__ << " " << __LINE__ << std::endl;
        exit(1);
    }
}

CANServerSocket::~CANServerSocket()
{
}
