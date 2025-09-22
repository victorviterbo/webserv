/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clientSocket.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:16:17 by victorviter       #+#    #+#             */
/*   Updated: 2025/09/22 17:16:56 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <sys/socket.h>

class clientSocket {
	public :
	// CONSTRUCTORS
		clientSocket();
		clientSocket(clientSocket &other);
		clientSocket &operator=(clientSocket &other);
	//DESTUCTORS
		~clientSocket();
	//GETTERS
	//SETTERS
	//MEMBER FUNCTIONS
	private :
		struct sockaddr_in	client_addr;
};