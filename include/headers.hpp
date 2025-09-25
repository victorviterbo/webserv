/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:15:31 by ego               #+#    #+#             */
/*   Updated: 2025/09/25 15:26:11 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <arpa/inet.h>
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <netinet/in.h>
#include <poll.h>
#include <sstream>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>

#define ALL_FDS -1
#define DEFAULT_EVENT -1
#define NO_TIMEOUT -1
#define SERVER_IDX 0

enum Method
{
	GET,
	POST,
	DELETE
};

typedef enum FileStatus
{
	EXISTS		= 1,	//0 0 0 0 0 0 0 1
	FILE_ROK	= 3,	//0 0 0 0 0 0 1 1
	FILE_WOK	= 5,	//0 0 0 0 0 1 0 1
	FILE_RWOK	= 7,	//0 0 0 0 0 1 1 1
	FILE_XOK	= 9,	//0 0 0 0 1 0 0 1
	FILE_RXOK	= 11,	//0 0 0 0 1 0 1 1
	FILE_WXOK	= 13,	//0 0 0 0 1 1 0 1
	FILE_RWXOK	= 15,	//0 0 0 0 1 1 1 1
	FILE_CGI	= 24,	//0 0 0 1 0 0 0 0
	DIR			= 33,   //0 0 1 0 0 0 0 1
	DIR_ROK		= 35,   //0 0 1 0 0 0 1 1
	DIR_WOK		= 37,   //0 0 1 0 0 1 0 1
	DIR_RWOK	= 39,   //0 0 1 0 0 1 1 1
	DIR_XOK		= 41,   //0 0 1 0 1 0 0 1
	DIR_RXOK	= 43,   //0 0 1 0 1 0 1 1
	DIR_WXOK	= 45,   //0 0 1 0 1 1 0 1
	DIR_RWXOK	= 47,   //0 0 1 0 1 1 1 1
	PERM_ISSUE	= 64,	//0 1 0 0 0 0 0 0
	BUSY		= 128,	//1 0 0 0 0 0 0 0
}	eFileStatus;
