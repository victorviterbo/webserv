/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:12:49 by ego               #+#    #+#             */
/*   Updated: 2025/09/24 23:36:27 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Request.hpp"

Request::Request(void) {}

Request::Request(const Request &other)
{
	*this = other;
	return ;
}

Request::Request(const std::string &raw)
{
	std::istringstream	stream(raw);
	std::string			line;

	if (std::getline(stream, line))
	{
		std::istringstream	firstLine(line);
		std::string			methodStr;

		firstLine >> methodStr >> _requestTarget >> _version;
		if (methodStr == "GET") _method = GET;
		else if (methodStr == "POST") _method = POST;
		else if (methodStr == "DELETE") _method = DELETE;
		else _method = ERR;
	}

	while (std::getline(stream, line) && line != "\r")
	{
		size_t	pos = line.find(':');

		if (pos != std::string::npos)
		{
			std::string	key = line.substr(0, pos);
			std::string	value = line.substr(pos + 1);
			_headers[key] = value;
		}
	}

	std::ostringstream	bodyStream;
	bodyStream << stream.rdbuf();
	_rawBody = bodyStream.str();
}

Request &Request::operator=(const Request &other)
{
	if (this != &other)
	{
		_method = other._method;
		_requestTarget = other._requestTarget;
		_version = other._version;
		_rawBody = other._rawBody;
		_headers = other._headers;
	}
	return (*this);
}

Request::~Request(void) {}

methodType	Request::getMethod(void) const
{
	return (_method);
}

std::string	Request::getRequestTarget(void) const
{
	return (_requestTarget);
}

std::string Request::getVersion(void) const
{
	return (_version);
}

std::string Request::getRawBody(void) const
{
	return (_rawBody);
}

std::map<std::string, std::string>	Request::getHeaders(void) const
{
	return (_headers);
}

std::ostream	&operator<<(std::ostream &os, const Request &src)
{
	methodType									method = src.getMethod();
	const std::map<std::string, std::string>	&headers = src.getHeaders();
	std::string									methodStr;

	if (method == GET) methodStr = "GET";
	else if (method == POST) methodStr = "POST";
	else if (method == DELETE) methodStr = "DELETE";
	else methodStr = "Unknown";

	os << "Method:\t\t" << methodStr << std::endl
		<< "Target:\t\t" << src.getRequestTarget() << std::endl
		<< "Version:\t" << src.getVersion() << std::endl
		<< "Headers:\t" << std::endl;
	for (std::map<std::string, std::string>::const_iterator it = headers.begin(); it != headers.end(); ++it)
		os << "\t\t" << it->first << ": " << it->second << std::endl;
	os << "Body:\n" << src.getRawBody() << std::endl;
	return (os);
}
