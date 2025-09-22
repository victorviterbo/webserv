/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverPoll.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:25:15 by victorviter       #+#    #+#             */
/*   Updated: 2025/09/22 18:39:57 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define ALL_FDS -1
#define DEFAULT_EVENT -1
#define NO_TIMEOUT -1

#include "serverSocket.hpp"
#include "clientSocket.hpp"

#include <vector>
#include <unordered_map>
#include <poll.h>


//serverPoll contains all the variables and function that pertains to the poll
//function which is used to monitor fd activity and availability for I/O operations
//see I/O multiplexing
//first element of vector will always be server fd which will not change
//following elements are clients fds that are dynamically created and destroyed

class serverPoll : public serverSocket {
	public :
	// CONSTRUCTORS
		serverPoll();
		serverPoll(const serverPoll &other);
		serverPoll &operator=(const serverPoll &other);
	//DESTUCTORS
		~serverPoll();
	//GETTERS
	//SETTERS
	//MEMBER FUNCTIONS
		void	pollAdd(serverSocket &sock, int event);
		int		pollWait(int TimeOut);
		int		pollWatchRevent();
		int		pollWatchReventTyped(int eventType);
	private :
		static const unsigned int				_poll_count = 10000;	//number of fds simultaneously handled by poll (different from backlog which is number of connections pending 'accept')
		std::vector<struct pollfd>				_poll_fds;				//vector of fds (will be of len _poll_count)
		std::unordered_map<int, ISocket>		_socket_map;			//the int is the actual poll fd and the map connects it to the serverSocket object
};