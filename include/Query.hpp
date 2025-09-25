/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Query.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:19:23 by victorviter       #+#    #+#             */
/*   Updated: 2025/09/25 18:12:45 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "headers.hpp"
#include "Request.hpp"
#include "utils.hpp"

class Query {
	public :
	// CONSTRUCTORS
		Query();
		Query(const Query &other);
		Query &operator=(const Query &other);
	//DESTUCTORS
		~Query();
	//GETTERS
	//SETTERS
	//MEMBER FUNCTIONS
		int			queryRespond();
		int			queryGet();
		int			queryPost();
		int			queryDelete();
		int			queryError();
		int			setRessourceStatus();
		int			queryCGIRun();
	private :
		typedef int					(Query::*queryMethod)();
		static const queryMethod	_queryExecute[4];
		std::string					_query_str;
		Request						_query;
		int							_err_code;
		std::string					_ressource;
		int							_ressource_status;
		bool						_cgi_request;
};

const Query::queryMethod	Query::_queryExecute[4] = {
	&Query::queryGet,
	&Query::queryPost, 
	&Query::queryDelete,
	&Query::queryError
};
