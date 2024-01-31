/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:14:23 by bfresque          #+#    #+#             */
/*   Updated: 2024/01/25 14:01:57 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

/********************************** getter **********************************/

std::string	Contact::get_first_name(void) const
{
	return (this->_first_name);
}

std::string	Contact::get_last_name(void) const
{
	return (this->_last_name);
}

std::string	Contact::get_nick_name(void) const
{
	return (this->_nick_name);
}

std::string	Contact::get_phone_num(void) const
{
	return (this->_phone_num);
}

std::string	Contact::get_secret(void) const
{
	return (this->_secret);
}

/********************************** setter **********************************/

void	Contact::set_first_name(std::string str)
{
	this->_first_name = str;
}

void	Contact::set_last_name(std::string str)
{
	this->_last_name = str;
}

void	Contact::set_nick_name(std::string str)
{
	this->_nick_name = str;
}

void	Contact::set_phone_num(std::string str)
{
	this->_phone_num = str;
}

void	Contact::set_secret(std::string str)
{
	this->_secret = str;
}
