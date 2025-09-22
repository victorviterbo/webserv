/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISocket.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:09:59 by victorviter       #+#    #+#             */
/*   Updated: 2025/09/22 18:22:37 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

typedef enum e_socketTypes
{
	CLIENT,
	SERVER
}	t_socketType;

class ISocket {
	public :
	//DESTUCTORS
		virtual ~ISocket();
	//GETTERS
		virtual t_socketType	getType() const = 0;
	//SETTERS
	//MEMBER FUNCTIONS
		virtual int	getFd() const = 0;
	private :
		t_socketType		_socket_type;
};