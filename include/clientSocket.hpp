/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clientSocket.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:16:17 by victorviter       #+#    #+#             */
/*   Updated: 2025/09/23 14:26:34 by victorviter      ###   ########.fr       */
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

class clientSocket {
	public :
	// CONSTRUCTORS
		clientSocket();
		clientSocket(const clientSocket &other);
		clientSocket &operator=(const clientSocket &other);
	//DESTUCTORS
		~clientSocket();
	//GETTERS
		int					getFd();
		struct sockaddr_in	&getClientAddr();
		socklen_t			&getClientLen();
	//SETTERS
		void				setFd(int fd);
	//MEMBER FUNCTIONS
		int	handleEvent(short revent);
	private :
		int					_client_fd;
		struct sockaddr_in	_client_addr;
		socklen_t			_client_len;
};