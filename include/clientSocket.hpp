/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clientSocket.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:16:17 by victorviter       #+#    #+#             */
/*   Updated: 2025/09/24 13:40:26 by ego              ###   ########.fr       */
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