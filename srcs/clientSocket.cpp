/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clientSocket.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:16:23 by victorviter       #+#    #+#             */
/*   Updated: 2025/09/22 18:56:23 by victorviter      ###   ########.fr       */
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
    this->_client_addr = other._client_addr;
    this->_client_len = other._client_len;
}

clientSocket::~clientSocket() {}

struct sockaddr_in	&clientSocket::getClientAddr()
{
	return (this->_client_addr);
}

socklen_t			&clientSocket::getClientLen()
{
	return (this->_client_len);
}
