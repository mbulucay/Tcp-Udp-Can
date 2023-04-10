#include <CanClientSocket.hpp>
#include <iostream>
#include <arpa/inet.h> 
#include <netinet/in.h>
#include <unistd.h>

CANClientSocket::CANClientSocket(const std::string& can_name) : m_can_name(can_name)
{

}

CANClientSocket::~CANClientSocket() {}

