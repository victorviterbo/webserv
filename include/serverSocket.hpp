/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverSocket.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 13:40:49 by victorviter       #+#    #+#             */
/*   Updated: 2025/09/24 13:37:48 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <cstring>
#include <string.h>

#include "clientSocket.hpp"

//serverSocket contains all the variables and functions that pertains to socket handling
//including initialisation, setting up the addresses of the client and server,
//accepting, listening and ending connections

class serverSocket {
	public :
	// CONSTRUCTORS
		serverSocket();
		serverSocket(const serverSocket &other);
		serverSocket &operator=(const serverSocket &other);
	//DESTUCTORS
		~serverSocket();
	//GETTERS
		int					getFd();
	//SETTERS
	//MEMBER FUNCTIONS
		int					socketInit(int domain, int type, int protocol);
		int					socketBind(int portNumber);
		clientSocket		*socketAcceptClient();
		//bool				setSockOpt(); //TODO set options for poll (see exemple below)
	private :
		static const unsigned int	_backlog = 100;		//number of connections pending 'accept' that can be queued
   		int							_server_fd;			//server file descriptor
		int							_domain;			//protocol family - AF_...
		int							_type;				//communication semantics - SOCK_...
		int							_protocol;			//specific protocol - 0 for standard in the domain
		struct sockaddr_in			_server_addr;
};

/*
// Set socket options to reuse address
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        std::cerr << "Failed to set socket options: " << strerror(errno) << std::endl;
        close(server_fd);
        return EXIT_FAILURE;
    }
*/