/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:08:53 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/11 09:52:30 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>

# define RESET	"\033[0m"
# define RED		"\033[1;31m"
# define GREEN	"\033[1;32m"
# define WHITE	"\033[1;37m"

struct Data { int value; };

class Serializer {
	private:
		Serializer();
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
		~Serializer();
	public:
		static uintptr_t		serialize(Data* ptr);
		static Data*			deserialize(uintptr_t raw);
};

#endif