/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:14:31 by bfresque          #+#    #+#             */
/*   Updated: 2024/02/01 09:50:04 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
	std::cout << std::endl;
	std::cout << " * * * * * * * Welcome in PhoneBook !! * * * * * * *" << std::endl;
	std::cout << " *                                                 *" << std::endl;
	std::cout << " * To add a new contact please write : ADD         *" << std::endl;
	std::cout << " * To search a contact please write : SEARCH       *" << std::endl;
	std::cout << " * To leave please write : EXIT                    *" << std::endl;
	std::cout << " *                                                 *" << std::endl;
	std::cout << " * * * * * * * * * * * * * * * * * * * * * * * * * *" << std::endl;
	std::cout << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << std::endl;
	std::cout << " Sorry to see you go... " << std::endl;
	std::cout << " PhoneBook destroyed !!!" << std::endl;
	std::cout << std::endl;
	return ;
}

void	PhoneBook::add(void)
{
	std::string	str;

	str = "";
	if (this->_index > 7)
		std::cout << " Warning : overwriting " << this->_contacts[this->_index % 8].get_first_name() << std::endl;
	while (!std::cin.eof() && str == "")
	{
		std::cout << " Enter a first name: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].set_first_name(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << " Enter " << this->_contacts[this->_index % 8].get_first_name() << "'s last name: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].set_last_name(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << " Enter " << this->_contacts[this->_index % 8].get_first_name() << "'s nickname: "; 
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].set_nick_name(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << " Enter " << this->_contacts[this->_index % 8].get_first_name() << "'s phone number: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].set_phone_num(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << " Enter " << this->_contacts[this->_index % 8].get_first_name() << "'s darkest secret: ";
		if (std::getline(std::cin, str) && str != "")
		{
			this->_contacts[this->_index % 8].set_secret(str);
			std::cout << " " << this->_contacts[this->_index % 8].get_first_name() << \
				" successfully added to phonebook [" << this->_index % 8 + 1 << "/8]" << std::endl;
				std::cout << std::endl;
		}
	}
	this->_index++;
}

std::string	add_spaces_before(int n)
{
	std::string	str;

	while (n--)
		str.append(" ");
	return (str);
}

std::string	set_point(std::string str, long unsigned max)
{
	if (str.size() > max)
	{
		str.resize(max);
		str[str.size() - 1] = '.';
	}
	return (str);
}

int	search_print(Contact contacts[8])
{
	char	index;
	int		nb_contacts;
	std::string	str;

	std::cout << ".___________________________________________." << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	index = '0';
	nb_contacts = 0;
	while (++index <= '8')
	{
		if (contacts[index - 1 - '0'].get_first_name().size() && ++nb_contacts)
			{
				str = index;

				str = set_point(str, 10);
				std::cout << "|" << add_spaces_before(10 - str.size()) << str;
				
				str = set_point(contacts[index - 1  - '0'].get_first_name(), 10);
				std::cout << "|" << add_spaces_before(10 - str.size()) << str;

				str = set_point(contacts[index - 1 - '0'].get_last_name(), 10);
				std::cout << "|" << add_spaces_before(10 - str.size()) << str;

				str = set_point(contacts[index - 1 - '0'].get_nick_name(), 10);
				std::cout << "|" << add_spaces_before(10 - str.size()) << str;

				std::cout << "| " << std::endl;
			}
	}
	return (nb_contacts);
}

void	display_contact_index(Contact contact)
{
	std::cout << std::endl << " Requesting contact informations ..." << std::endl;
	if (!contact.get_first_name().size())
	{
		std::cout << " Failed to get contact's informations" << std::endl;
		return ;
	}
	std::cout << " First name : " << contact.get_first_name() << std::endl;
	std::cout << " Last name : " << contact.get_last_name() << std::endl;
	std::cout << " Nickname : " << contact.get_nick_name() << std::endl;
	std::cout << " Phone number : " << contact.get_phone_num() << std::endl;
	std::cout << " Darkest secret : " << contact.get_secret() << std::endl;
}


void	PhoneBook::search(void)
{
	std::string	str;

	if (!search_print(this->_contacts))
	{
		std::cout << std::endl << " Phonebook is empty!" << std::endl;
		std::cout << std::endl;
		return ;
	}
	while (!std::cin.eof())
	{
		std::cout << " Please select an index : ";
		if (std::getline(std::cin, str) && str != "")
		{
			if (str.size() == 1 && str[0] >= '1' && str[0] <= '8' && this->_contacts[str[0] - 1 - '0'].get_first_name().size())
				break ;
		}
		if (str != "")
			std::cout << " Invalid index!" << std::endl;
	}
	if (!std::cin.eof())
	{
		display_contact_index(this->_contacts[str[0] - 1 - '0']);
		std::cout << std::endl;
	}
}

