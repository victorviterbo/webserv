/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerSocket.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 13:40:49 by victorviter       #+#    #+#             */
/*   Updated: 2025/09/22 18:19:53 by victorviter      ###   ########.fr       */
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

//serverSocket contains all the variables and functions that pertains to socket handling
//including initialisation, setting up the addresses of the client and server,
//accepting, listening and ending connections

#include "ISocket.hpp"

class serverSocket : public ISocket {
	public :
	// CONSTRUCTORS
		serverSocket();
		serverSocket(const serverSocket &other);
		serverSocket &operator=(const serverSocket &other);
	//DESTUCTORS
		~serverSocket();
	//GETTERS
		int					getFd();
		struct sockaddr_in	&getClientAddr();
		socklen_t			&getClientLen();
	//SETTERS
	//MEMBER FUNCTIONS
		int					socketInit(int domain, int type, int protocol);
		int					socketBind(int portNumber);
		//bool				setSockOpt();
	private :
		static const unsigned int	_backlog = 100;		//number of connections pending 'accept' that can be queued
   		int							_server_fd;			//server file descriptor
		int							_domain;			//protocol family - AF_...
		int							_type;				//communication semantics - SOCK_...
		int							_protocol;			//specific protocol - 0 for standard in the domain
		struct sockaddr_in			_server_addr;
};