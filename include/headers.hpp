/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:15:31 by ego               #+#    #+#             */
/*   Updated: 2025/09/25 14:33:39 by victorviter      ###   ########.fr       */
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
	FILE_X,
	FILE_R,
	FILE_W,
	FILE_XR,
	FILE_
}	t_FileStatus;