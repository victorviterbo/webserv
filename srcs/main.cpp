/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 10:44:51 by victorviter       #+#    #+#             */
/*   Updated: 2025/09/22 13:52:54 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serverSocket.hpp"

int main()
{
	serverSocket    s;
	int				client_fd;
	static int		backlog = 5;	//how many incomming connections can be queued while handling incomming connection
	char 			buffer[1024];

	if (s.socketInit(AF_INET, SOCK_STREAM, 0) == -1)
	{
		std::cerr << "Socket init failed" << std::endl;
		return (1);
	}
	if (s.socketBind(12345) == -1)
	{
		std::cerr << "Socket bind failed" << std::endl;
		return (1);
	}
	if (listen(s.getServerFd(), backlog) == -1)
	{
		std::cerr << "Socket listen failed" << std::endl;
		return (1);
	}
	while (true)
	{
        client_fd = accept(s.getServerFd(), (struct sockaddr*)&s.getClientAddr(), &s.getClientLen());
        if (client_fd == -1) {
            std::cerr << "Accept failed\n";
            continue;
        }

        std::cout << "Client connected: " << inet_ntoa(s.getClientAddr().sin_addr) << "\n"; //TODO : remove inet_ntoa forbidden function

        // Echo loop
        ssize_t bytes_read;
        while ((bytes_read = recv(client_fd, buffer, sizeof(buffer), 0)) > 0) {
            if (send(client_fd, buffer, bytes_read, 0) == -1) {
                std::cerr << "Send failed\n";
                break;
            }
        }

        if (bytes_read == -1)
            std::cerr << "Recv failed\n";

        close(client_fd);
        std::cout << "Client disconnected\n";
    }
	return (0);
}