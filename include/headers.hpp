/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:15:31 by ego               #+#    #+#             */
/*   Updated: 2025/09/25 17:59:54 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <arpa/inet.h>
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <strings.h>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <netinet/in.h>
#include <poll.h>
#include <sstream>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <vector>

#define ALL_FDS -1
#define DEFAULT_EVENT -1
#define NO_TIMEOUT -1
#define SERVER_IDX 0

#define NOT_FOUND 0
#define PERM_ISSUE 1
#define IS_DIR 2
#define PERM_ROK 4
#define PERM_WOK 8
#define PERM_XOK 16
#define IS_CGI 32
#define EXISTS 128

enum Method
{
	GET,
	POST,
	DELETE
};
