/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 10:44:51 by victorviter       #+#    #+#             */
/*   Updated: 2025/09/23 14:31:38 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serverSocket.hpp"
#include "clientSocket.hpp"
#include "serverPoll.hpp"

int main()
{
	serverSocket    servSocket;
	static int		backlog = 5;	//how many incomming connections can be queued while handling incomming connection
	serverPoll		pollServer;

	if (servSocket.socketInit(AF_INET, SOCK_STREAM, 0) == -1)
		return (1);
	if (servSocket.socketBind(12345) == -1)
		return (1);
	if (listen(servSocket.getFd(), backlog) == -1) //TODO make this a serverSocket member function
	{
		std::cerr << "Socket listen failed" << std::endl;
		return (1);
	}
	pollServer.setServSocket(&servSocket); //Start monitoring the server socket as an input source
	while (true)
	{
		if (pollServer.pollWait(NO_TIMEOUT) == -1)
			return (-1); //TODO do a clean exit, probably will see that at the end when we know what need to be closes/cleaned
		if (pollServer.pollWatchRevent() == -1)
			return (-1);
	}
	return (0);
}