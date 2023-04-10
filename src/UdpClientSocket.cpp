#include <UdpClientSocket.hpp>
#include <iostream>
#include <arpa/inet.h> 


UDPClientSocket::UDPClientSocket(std::string ip, uint32_t port)
{
    if ((m_sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    m_servaddr.sin_family = AF_INET; 
    m_servaddr.sin_port = htons(port); 
    m_servaddr.sin_addr.s_addr = inet_addr(ip.c_str());
}

UDPClientSocket::~UDPClientSocket()
{}


void UDPClientSocket::send(std::string message)
{
    sendto(m_sockfd, (void *)message.c_str(), message.size(), 
        MSG_CONFIRM, (const struct sockaddr *) &m_servaddr,  
            sizeof(m_servaddr));
}
