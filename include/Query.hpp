/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Query.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:19:23 by victorviter       #+#    #+#             */
/*   Updated: 2025/09/25 15:08:08 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Query.hpp"
#include "Resquest.hpp"
#include <cstring>
#include <string.h>
#include <sys/stat.h>

class Query {
	public :
	// CONSTRUCTORS
		Query();
		Query(std::string input);
		Query(const Query &other);
		Query &operator=(const Query &other);
	//DESTUCTORS
		~Query();
	//GETTERS
	//SETTERS
	//MEMBER FUNCTIONS
		int		parseRequest(std::string input);
		int		queryRespond();
		int		queryGet();
		int		queryPost();
		int		queryDelete();
		int		setRessourceStatus();
		int		queryCGIRun();
	private :
    	typedef void (Query::*MemberFunc)();
		static const queryMethod _queryExecute[METHOD_COUNT];
		parser					_query;
		int						_err_code;
		std::string				_ressource;
		int						_ressource_status;
		bool					_cgi_request;
};

const Query::MemberFunc	Query::_queryExecute[Query::ACTION_COUNT] = {
						&Query::queryGet,
						&Query::queryPost, 
						&Query::queryDelete,
						&Query::queryError
};
