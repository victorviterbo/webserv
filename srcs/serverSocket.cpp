/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverSocket.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 13:40:44 by victorviter       #+#    #+#             */
/*   Updated: 2025/09/22 13:51:23 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serverSocket.hpp"

serverSocket::serverSocket() {}

serverSocket::serverSocket(serverSocket &other)
{
	this->_server_fd = other._server_fd;
	this->_domain = other._domain;
	this->_type = other._type;
	this->_protocol = other._protocol;
	this->_server_addr = other._server_addr;
	this->_client_addr = other._client_addr;
	this->_client_len = other._client_len;
}

serverSocket &serverSocket::operator=(serverSocket &other)
{
	this->_server_fd = other._server_fd;
	this->_domain = other._domain;
	this->_type = other._type;
	this->_protocol = other._protocol;
	this->_server_addr = other._server_addr;
	this->_client_addr = other._client_addr;
	this->_client_len = other._client_len;
	return (*this);
}

serverSocket::~serverSocket()
{
	if (this->_server_fd > 0)
		close(this->_server_fd);
}

int	serverSocket::getServerFd()
{
	return (this->_server_fd);
}

struct sockaddr_in	&serverSocket::getClientAddr()
{
	return (this->_client_addr);
}

socklen_t			&serverSocket::getClientLen()
{
	return (this->_client_len);
}

int	serverSocket::socketInit(int domain, int type, int protocol)
{
	this->_server_fd = socket(domain, type, protocol);
	this->_domain = domain;
	this->_type = type;
	this->_protocol = protocol;
	return (this->_server_fd);
}

int		serverSocket::socketBind(int portNumber)
{
	(void)this->_client_addr;
	(void)this->_client_len;
	std::memset(&this->_server_addr, 0, sizeof(this->_server_addr));
	this->_server_addr.sin_family = this->_domain;
	this->_server_addr.sin_addr.s_addr = INADDR_ANY; //Bind to all available interfaces
	this->_server_addr.sin_port = htons(portNumber); //port # above 1024 are not priviledged
	return (::bind(this->_server_fd, (struct sockaddr*)&this->_server_addr, sizeof(this->_server_addr)));
}