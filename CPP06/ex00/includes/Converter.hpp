/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:58:00 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/29 09:58:52 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <limits>
# include <cstdlib>
# include <iomanip>

typedef enum
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO
}	t_type;

class Converter
{
	public:
		Converter();
		Converter(const Converter &other);
		~Converter();
		Converter &operator=(const Converter &other);

		static bool isChar(const std::string &input);
		static bool isInt(const std::string &input);
		static bool isFloat(const std::string &input);
		static bool isDouble(const std::string &input);
		static bool isPseudo(const std::string &input);
		
		static void printChar(char c, const std::string &input);
		static void printInt(int i, const std::string &input);
		static void printFloat(float f, const std::string &input);
		static void printDouble(double d, const std::string &input);
		static void printPseudo(const std::string &input);
		static void printInput(long double num, const std::string &input);

		static bool verifOver(const std::string &str, t_type type);
		static void convert(const std::string &input);
};

#endif
