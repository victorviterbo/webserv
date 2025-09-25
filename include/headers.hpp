/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:15:31 by ego               #+#    #+#             */
/*   Updated: 2025/09/25 15:08:48 by victorviter      ###   ########.fr       */
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

typedef enum e_FileStatus
{
	FILE		= 1,	//0 0 0 0 0 0 0 1
	FILE_R		= 3,	//0 0 0 0 0 0 1 1
	FILE_W		= 5,	//0 0 0 0 0 1 0 1
	FILE_RW		= 7,	//0 0 0 0 0 1 1 1
	FILE_X		= 9,	//0 0 0 0 1 0 0 1
	FILE_CGI	= 25,	//0 0 0 1 1 0 0 1
	IS_DIR		= 33,	//0 0 1 0 0 0 0 1
	PERM_ISSUE	= 65,	//0 1 0 0 0 0 0 1
	EXISTS		= 255,	//1 1 1 1 1 1 1 1
}	t_FileStatus;
