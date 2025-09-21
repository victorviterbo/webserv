/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverSocket.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 13:40:49 by victorviter       #+#    #+#             */
/*   Updated: 2025/09/21 13:58:57 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class serverSocket {
	public :
	// CONSTRUCTORS
		serverSocket();
		serverSocket(serverSocket &other);
		serverSocket &operator=(serverSocket &other);
	//DESTUCTORS
		~serverSocket();
	//GETTERS
		int	*getFlags();
		int	getServerFd();
	//SETTERS
	//MEMBER FUNCTIONS
		int		initSocket(int ipv, int sockstream, int protocol);
		int		bind();
	private :
		int		*_flags;
   		int					_server_fd;
		struct sockaddr_in	server_addr;
		struct sockaddr_in	client_addr;
		socklen_t			client_len;
};