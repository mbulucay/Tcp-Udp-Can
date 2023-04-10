#include <UdpServerSocket.hpp>
#include <iostream>
#include <arpa/inet.h> 

UDPServerSocket::UDPServerSocket(std::string ip, uint32_t port)
{

	if((m_sockfd = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0){
        std::cerr << "socket" << std::endl;
    }

    m_servaddr.sin_family = AF_INET;
    m_servaddr.sin_port = htons(port);
    m_servaddr.sin_addr.s_addr = inet_addr(ip.c_str());

    if(bind(m_sockfd, (struct sockaddr *) &m_servaddr, sizeof(m_servaddr)) < 0){
        std::cerr << "binding" << std::endl;
    }

}

UDPServerSocket::~UDPServerSocket()
{}