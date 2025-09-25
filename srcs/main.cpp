/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 10:44:51 by victorviter       #+#    #+#             */
/*   Updated: 2025/09/25 17:28:01 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.hpp"
#include "serverSocket.hpp"
#include "clientSocket.hpp"
#include "serverPoll.hpp"
#include "Request.hpp"

int	main(void)
{
	std::string	raw("POST /submit HTTP/1.1\r\nHost: localhost:8080\r\nContent-Length: 16\r\n\r\nname=Alice&age=5");
	Request	test(raw);

	std::cout << test << std::endl;
}

/*
int main()
{
	serverSocket    servSocket;
	static int		backlog = 5;	//how many incomming connections can be queued while handling incomming connection
	serverPoll		pollServer;

	if (servSocket.socketInit(AF_INET, SOCK_STREAM, 0) == -1)
		return (1);
	if (servSocket.socketBind(12344) == -1)
	{
		if (servSocket.socketBind(12345) == -1)
			return (1);
	}
	if (listen(servSocket.getFd(), backlog) == -1) //TODO make this a serverSocket member function
	{
		std::cerr << "Socket listen failed" << std::endl;
		return (1);
	}
	pollServer.setServSocket(&servSocket); //Start monitoring the server socket as an input source
	while (true)
	{
		if (pollServer.pollWatchRevent() == -1)
			return (-1); //TODO do a clean exit, probably will see that at the end when we know what need to be closes/cleaned
	}
	return (0);
}
*/