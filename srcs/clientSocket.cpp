/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clientSocket.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:16:23 by victorviter       #+#    #+#             */
/*   Updated: 2025/09/23 16:48:25 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clientSocket.hpp"

clientSocket::clientSocket()
{
	this->_client_len = sizeof(this->_client_addr);
}

clientSocket::clientSocket(const clientSocket &other) : _client_addr(other._client_addr), _client_len(other._client_len) {}

clientSocket &clientSocket::operator=(const clientSocket &other)
{
	if (this != &other)
	{
		this->_client_addr = other._client_addr;
		this->_client_len = other._client_len;
	}
	return (*this);
}

clientSocket::~clientSocket() {}

struct sockaddr_in	&clientSocket::getClientAddr()
{
	return (this->_client_addr);
}

socklen_t   &clientSocket::getClientLen()
{
	return (this->_client_len);
}

int     clientSocket::getFd()
{
	return (this->_client_fd);
}

void    clientSocket::setFd(int fd)
{
	this->_client_fd = fd;
}

int	clientSocket::handleEvent(short revent)
{
	/* For now it just echoes back the message for testing purposes */
	char 	    buffer[10];
	ssize_t     bytes_read;

	std::cout << "clientSocket is handling the event on fd " << this->_client_fd << std::endl;
	while ((bytes_read = recv(this->_client_fd, buffer, sizeof(buffer), 0)) > 0)
	{
		std::cout << "Reading input" << std::endl;
		if (std::strncmp(buffer, "close", 5) == 0)
		{
			std::cout << "Closing connection ..." << std::endl;
			return (-1);
		}
		else if (send(this->_client_fd, buffer, bytes_read, 0) == -1)
		{
			std::cerr << "Send failed\n";
			return (-1);
		}
			return (0);
	}
	(void)revent;
	return (0);
}
