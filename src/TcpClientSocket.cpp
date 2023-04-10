#include <TcpClientSocket.hpp>
#include <iostream>
#include <arpa/inet.h> 
#include <netinet/in.h>
#include <unistd.h>

TCPClientSocket::TCPClientSocket(std::string ip, uint32_t port)
{

    int m_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(m_sockfd < 0){
        std::cerr << "socket" << std::endl;
    }

    m_servaddr.sin_family = AF_INET;
    m_servaddr.sin_addr.s_addr = inet_addr(ip.c_str());
    m_servaddr.sin_port = htons(port);

    while(connect(m_sockfd , (struct sockaddr *)&m_servaddr , sizeof(m_servaddr)) == -1){
        close(m_sockfd);
        m_sockfd = socket(AF_INET , SOCK_STREAM , 0);
    }
}

TCPClientSocket::~TCPClientSocket()
{
    close(client);
}

