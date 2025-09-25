/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:05:02 by victorviter       #+#    #+#             */
/*   Updated: 2025/09/25 18:12:12 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

bool endsWith(const std::string& str, const std::string& suffix)
{
    if (str.length() < suffix.length()) {
        return false;
    }
    return str.rfind(suffix) == (str.length() - suffix.length());
}