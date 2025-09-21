/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverSocket.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 13:40:44 by victorviter       #+#    #+#             */
/*   Updated: 2025/09/21 14:10:04 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serverSocket.hpp"

serverSocket::serverSocket() {}

serverSocket::serverSocket(serverSocket &other)
{
    for (unsigned int i = 0; i < 3; i++)
        this->_flags[i] = other._flags[i];
    this->_server_fd = other.getServerFd();
}

serverSocket &serverSocket::operator=(serverSocket &other)
{
    for (unsigned int i = 0; i < 3; i++)
        this->_flags[i] = other._flags[i];
    this->_server_fd = other.getServerFd();
    return (*this);
}

serverSocket::~serverSocket() {}

int	*serverSocket::getFlags()
{
    return (this->_flags);
}

int	serverSocket::getServerFd()
{
    return (this->_server_fd);
}

int	serverSocket::initSocket(int ipv, int sockstream, int protocol)
{
    this->_server_fd = socket(ipv, sockstream, protocol);
    return (this->_server_fd);
}

int		serverSocket::bind()
{
    int ret;

    std::memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    ret = bind(this->_server_fd, &server_addr, sizeof(server_addr));
    return (ret);
}