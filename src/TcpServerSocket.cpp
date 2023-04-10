#include <TcpServerSocket.hpp>
#include <iostream>
#include <arpa/inet.h> 
#include <netinet/in.h>

TCPServerSocket::TCPServerSocket(std::string ip, uint32_t port, uint32_t backlog)
{

    m_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(m_sockfd < 0){
        std::cerr << "socket" << std::endl;
    }

    m_servaddr.sin_family = AF_INET;
    m_servaddr.sin_addr.s_addr = inet_addr(ip.c_str());
    m_servaddr.sin_port = htons(port);

    if(bind(m_sockfd, (struct sockaddr*)&m_servaddr, sizeof(m_servaddr)) < 0){
        std::cerr << "bind" << std::endl;
    }

    if(listen(m_sockfd, backlog) < 0){
        std::cerr << "listen" << std::endl;
    }
}

TCPServerSocket::~TCPServerSocket()
{}
