/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:12:49 by ego               #+#    #+#             */
/*   Updated: 2025/09/25 14:09:09 by ego              ###   ########.fr       */
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

	_error = NONE;
	if (std::getline(stream, line))
	{
		std::istringstream	firstLine(line);
		std::string			methodStr;

		if (!(firstLine >> methodStr >> _requestTarget >> _version))
		{
			_error = INVALID_REQUEST_LINE;
			return ;
		}
		if (methodStr == "GET") _method = GET;
		else if (methodStr == "POST") _method = POST;
		else _method = DELETE;
	}
	else
	{
		_error = INVALID_REQUEST_LINE;
		return ;
	}

	while (std::getline(stream, line) && line != "\r")
	{
		size_t	pos = line.find(':');

		if (pos != std::string::npos)
		{
			std::string	key = line.substr(0, pos);
			std::string	value = line.substr(pos + 1);
			if (!value.empty() && value[0] == ' ')
				value.erase(0, 1);
			if (!value.empty() && value[value.size() - 1] == '\r')
				value.erase(value.size() - 1);
			_headers[key] = value;
		}
		else
		{
			_error = INVALID_HEADER;
			return ;
		}
	}

	std::ostringstream	bodyStream;
	bodyStream << stream.rdbuf();
	_rawBody = bodyStream.str();
	if (_headers.count("Content-Length"))
	{
		size_t	expected = std::atoi(_headers["Content-Length"].c_str());
		if (_rawBody.size() != expected)
			_error = BAD_CONTENT_LENGTH;
	}
	return ;
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

Method	Request::getMethod(void) const
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

Request::ParseError	Request::getError(void) const
{
	return (_error);
}

std::ostream	&operator<<(std::ostream &os, const Request &src)
{
	Method										method = src.getMethod();
	const std::map<std::string, std::string>	&headers = src.getHeaders();
	std::string									methodStr;

	if (src.getError() != Request::NONE)
	{
		os << "Parse error detected: " << src.getError() << std::endl;
		return (os);
	}
	if (method == GET) methodStr = "GET";
	else if (method == POST) methodStr = "POST";
	else methodStr = "DELETE";

	os << "Method:\t\t" << methodStr << std::endl
		<< "Target:\t\t" << src.getRequestTarget() << std::endl
		<< "Version:\t" << src.getVersion() << std::endl
		<< "Headers:\t" << std::endl;
	for (std::map<std::string, std::string>::const_iterator it = headers.begin(); it != headers.end(); ++it)
		os << "\t\t" << it->first << ": " << it->second << std::endl;
	os << "Body:\n" << src.getRawBody() << std::endl;
	return (os);
}
