/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:29:42 by bfresque          #+#    #+#             */
/*   Updated: 2024/02/07 10:34:43 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

std::string replaceString(std::string line, std::string s1, std::string s2, int pos)
{
	line.erase(pos, s1.length());
	line.insert(pos, s2);
	return (line);
}