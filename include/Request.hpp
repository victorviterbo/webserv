/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:12:40 by ego               #+#    #+#             */
/*   Updated: 2025/09/25 14:24:55 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "headers.hpp"

class Request
{
	public:
		Request(void);
		Request(const Request &other);
		Request(const std::string &raw);
		Request	&operator=(const Request &other);
		~Request(void);

		enum ParseError
		{
			NONE,
			UNSUPPORTED_METHOD,
			INVALID_REQUEST_LINE,
			INVALID_HEADER,
			BAD_CONTENT_LENGTH
		};

		Method								getMethod(void) const;
		std::string							getRequestTarget(void) const;
		std::string							getVersion(void) const;
		std::string							getRawBody(void) const;
		std::map<std::string, std::string>	getHeaders(void) const;
		ParseError							getError(void) const;


	private:
		Method								_method;
		std::string							_requestTarget;
		std::string							_version;
		std::string							_rawBody;
		std::map<std::string, std::string>	_headers;
		ParseError							_error;
};

std::ostream	&operator<<(std::ostream &os, const Request &src);
