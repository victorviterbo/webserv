/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverSocket.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 13:40:49 by victorviter       #+#    #+#             */
/*   Updated: 2025/09/22 13:50:01 by victorviter      ###   ########.fr       */
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

class serverSocket {
	public :
	// CONSTRUCTORS
		serverSocket();
		serverSocket(serverSocket &other);
		serverSocket &operator=(serverSocket &other);
	//DESTUCTORS
		~serverSocket();
	//GETTERS
		int					getServerFd();
		struct sockaddr_in	&getClientAddr();
		socklen_t			&getClientLen();
	//SETTERS
	//MEMBER FUNCTIONS
		int					socketInit(int domain, int type, int protocol);
		int					socketBind(int portNumber);
		//bool				setSockOpt();
	private :
   		int					_server_fd;		//server file descriptor
		int					_domain;		//protocol family - AF_...
		int					_type;			//communication semantics - SOCK_...
		int					_protocol;		//specific protocol - 0 for standard in the domain
		struct sockaddr_in	_server_addr;
		struct sockaddr_in	_client_addr;
		socklen_t			_client_len;
};