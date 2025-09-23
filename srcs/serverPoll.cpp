/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverPoll.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:25:07 by victorviter       #+#    #+#             */
/*   Updated: 2025/09/23 16:20:41 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serverPoll.hpp"

serverPoll::serverPoll()
{
	this->_poll_fds.resize(this->_poll_count);
}

serverPoll::serverPoll(const serverPoll &other) : _poll_fds(other._poll_fds), _server(other._server) {}

serverPoll &serverPoll::operator=(const serverPoll &other)
{
	if (this != &other)
		this->_poll_fds = other._poll_fds;
	this->_server = other._server;
	return (*this);
}

serverPoll::~serverPoll()
{
	/*for (std::map<int, clientSocket *>::iterator it = this->_client_map.begin(); \
		it != this->_client_map.end(); ++it)
	{
		if (it->second)
			delete it->second;
	}*/
}

void	serverPoll::setServSocket(serverSocket *server)
{
	this->_server = server;								//keep track of server socket
	this->pollAdd(server->getFd(), POLLIN, NULL);		//start monitoring the server socket
}

serverSocket	*serverPoll::getServSocket()
{
	return (this->_server);
}

void	serverPoll::pollAdd(int fd, int event, clientSocket *client)
{
    struct pollfd new_poll_fd;
	new_poll_fd.fd = fd;
	new_poll_fd.events = event;
	for (unsigned int i = 0; i < this->_poll_count; ++i)
	{
		if (!this->_poll_fds[i].fd)
		{
			this->_poll_fds[i] = new_poll_fd;
			std::cout << "Added fd " << new_poll_fd.fd << " to the poll watchlist" << std::endl;
			break ;
		}
	}
	if (client)
	{
		std::cout << "Adding client to map" << std::endl;
		this->_client_map[new_poll_fd.fd] = client;
	}
}

int		serverPoll::pollRemove(int indx)
{
	int	success;

	success = close(this->_poll_fds[indx].fd);
	delete this->_client_map[this->_poll_fds[indx].fd];
	success += (this->_client_map.erase(this->_poll_fds[indx].fd) != 1);
	std::memset(&this->_poll_fds[indx], 0, sizeof(pollfd));
	return (success);
}

int		serverPoll::pollWait(int TimeOut)
{
	int	poll_count;

	std::cout << "Poll waiting on new Revent" << std::endl;
	poll_count = poll(&this->_poll_fds[0], this->_poll_count, TimeOut);
	if (poll_count == -1)
		std::cerr << "Poll failed: " << strerror(errno) << std::endl;
	else
		std::cout << "Poll detected new Revent" << std::endl;
	return (poll_count);
}

int		serverPoll::pollWatchRevent()
{
	static int iterations = 100;
	this->pollWait(NO_TIMEOUT);
	iterations--;
	if (iterations == 0)
	{
		std::cout << "iterated 100 times..." << std::endl;
		exit (1);
	}
	for (unsigned int i = 0; i < this->_poll_count; ++i)
	{
		if (this->_poll_fds[i].revents & POLLHUP || this->_poll_fds[i].revents & POLLERR)
		{
			if (this->_poll_fds[i].fd == this->_server->getFd())
			{
				std::cerr << "Server ended connection abrubtly, exiting..." << std::endl;
				continue ;
			}
			else
			{
				std::cout << "Closing connection with client index " << i << std::endl;
				this->pollRemove(i);
			}
		}
        else if (this->_poll_fds[i].revents & POLLIN)
		{
			std::cout << "Poll detected activity on Fd " << this->_poll_fds[i].fd << std::endl;
			if (this->_poll_fds[i].fd == this->_server->getFd())
			{
				std::cout << "New connection attempts detected" << std::endl;
				clientSocket *new_client;
				new_client = this->_server->socketAcceptClient();
				if (!new_client)
				{
					std::cerr << "Failed to accept new client" << std::endl;
					continue ;
				}
				this->pollAdd(new_client->getFd(), POLLIN, new_client);
			}
			else
			{
				std::cout << "Handling event for client with index " << i << std::endl;
				std::cout << "Address of client socket : " << this->_client_map[this->_poll_fds[i].fd] << std::endl;
				this->_client_map[this->_poll_fds[i].fd]->handleEvent(this->_poll_fds[i].revents);
			}
		}
		/*else
		{
			std::cerr << "Connection failed: " << strerror(errno) << std::endl;
			return (-1);
		}*/
	}
	return (0);
}
