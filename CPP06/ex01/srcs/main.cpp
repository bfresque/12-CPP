/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:01:08 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/10 17:01:29 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

int main()
{
	Data		myData;
	myData.value = 10;
	void*		raw = Serializer::serialize(&myData);
	Data*		ptr = Serializer::deserialize(raw);

	if (&myData == ptr)
		std::cout << "Serialization and deserialization successful." << std::endl;
	else
		std::cout << "Something went wrong." << std::endl;
	return (0);
}