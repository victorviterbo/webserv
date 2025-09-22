/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverPoll.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:25:07 by victorviter       #+#    #+#             */
/*   Updated: 2025/09/22 17:14:17 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serverPoll.hpp"

serverPoll::serverPoll()
{
	this->_poll_fds.resize(this->_poll_count);
}

serverPoll::serverPoll(const serverPoll &other) : _poll_fds(other._poll_fds), _socket_map(other._socket_map) {}

serverPoll &serverPoll::operator=(const serverPoll &other)
{
	if (this != &other)
	{
		this->_poll_fds = other._poll_fds;
		this->_socket_map = other._socket_map;
	}
	return (*this);
}

serverPoll::~serverPoll() {}

void	serverPoll::pollAdd(serverSocket &sock, int event)
{
    struct pollfd new_poll_fd;
	new_poll_fd.fd = sock.getFd();
	new_poll_fd.events = event;
	this->_socket_map[new_poll_fd.fd] = sock;
	for (unsigned int i = 0; i < this->_poll_count; ++i)
	{
		if (!this->_poll_fds[i].fd)
			this->_poll_fds[i] = new_poll_fd;
	}
}

int		serverPoll::pollWait(int TimeOut)
{
	int	poll_count;

	poll_count = poll(&this->_poll_fds[0], this->_poll_count, TimeOut);
	if (poll_count == -1) {
		std::cerr << "Poll failed: " << strerror(errno) << std::endl;
		return (-1);
	}
}

int		serverPoll::pollWatchRevent(int eventType, int fd)
{
	if (fd != ALL_FDS && fd >= 0)
	{
        if (eventType != DEFAULT_EVENT && (this->_poll_fds[fd].revents & eventType))
		{
			
		}
	}
	for (unsigned int i = 0; i < this->_poll_count; ++i)
	{
        if (eventType != DEFAULT_EVENT && (this->_poll_fds[i].revents & eventType))
		{
			
		}
	}
}
