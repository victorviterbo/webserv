/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverPoll.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:25:07 by victorviter       #+#    #+#             */
/*   Updated: 2025/09/22 18:56:02 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serverPoll.hpp"

serverPoll::serverPoll()
{
	this->_poll_fds.resize(this->_poll_count);
}

serverPoll::serverPoll(const serverPoll &other) : _poll_fds(other._poll_fds) {}

serverPoll &serverPoll::operator=(const serverPoll &other)
{
	if (this != &other)
		this->_poll_fds = other._poll_fds;
	return (*this);
}

serverPoll::~serverPoll() {}

void	serverPoll::pollAdd(int fd, int event)
{
    struct pollfd new_poll_fd;
	new_poll_fd.fd = fd;
	new_poll_fd.events = event;
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

int		serverPoll::pollWatchRevent()
{
	for (unsigned int i = 0; i < this->_poll_count; ++i)
	{
        if (this->_poll_fds[i].revents & POLLIN) //TODO implement Revent check for errors before check for input
		{
			if (i == SERVER_IDX) //TODO check if this is not gonna break ? better way to do this ?
				
		}
	}
}
