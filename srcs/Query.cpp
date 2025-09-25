/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Query.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:19:30 by victorviter       #+#    #+#             */
/*   Updated: 2025/09/25 15:03:19 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Query.hpp"

Query::Query() {}

Query::Query(std::string input)
{
	this->parseRequest(input);
	this->setRessourceStatus();
}

Query::Query(Query &other) : _parser(other._parser), _err_code(other._err_code) {}

Query &Query::operator=(Query &other)
{
	this->_parser = other._parser;
	this->_err_code = other._err_code;
}

Query::~Query() {}


int		Query::queryRespond(std::string input)
{
	this->_parser.parse(input);
	this->*_queryExecute[std::max(this->_parser.getMethod(), DELETE + 1)];
}

int		Query::setRessourceStatus(std::string ressource);
{
	struct stat file_stat;
	int			success;

	success = stat(fd, &file_stat);
	switch (success)
	{
		case ENOENT :
			std::cerr << "Ressource stat failed: " << strerror(errno) << std::endl;
			this->_err
	}
	else if ()
	switch (sb.st_mode & S_IFMT)
	{
		case S_IFREG:
			
			break;
        case S_IFDIR:  std::cout << "Directory"; break;
        case S_IFCHR:  std::cout << "Character device"; break;
        case S_IFBLK:  std::cout << "Block device"; break;
        case S_IFIFO:  std::cout << "FIFO/pipe"; break;
        case S_IFLNK:  std::cout << "Symlink"; break;
        case S_IFSOCK: std::cout << "Socket"; break;
        default:       std::cout << "Unknown"; break;
	}
}

int		queryGet();
int		queryPOST();
int		queryDelete();
int		queryCGIRun();