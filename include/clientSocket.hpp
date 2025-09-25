/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clientSocket.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:16:17 by victorviter       #+#    #+#             */
/*   Updated: 2025/09/25 14:15:55 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "headers.hpp"

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
