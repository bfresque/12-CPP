/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:01:08 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/11 09:53:44 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

int main() {
	Data		myData;
	myData.value = 10;

	uintptr_t	raw = Serializer::serialize(&myData);
	std::cout << WHITE << "Serialized " << RESET << "memory address (integer): " << raw << std::endl;

	Data*		ptr = Serializer::deserialize(raw);
	std::cout << WHITE << "Deserialized " << RESET << " memory address (pointer): " << ptr << std::endl <<std::endl;
	
	if (&myData == ptr)
		std::cout << GREEN << "Serialization and deserialization successful." << RESET << std::endl;
	else
		std::cout << RED << "Something went wrong." << RESET << std::endl;
	return (0);
}