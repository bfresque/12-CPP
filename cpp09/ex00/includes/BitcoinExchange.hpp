/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:32:45 by bfresque          #+#    #+#             */
/*   Updated: 2024/05/23 11:57:47 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BitcoinExchange_HPP
# define BitcoinExchange_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <ctime>
# include <string>
# include <cstdlib>

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENTA	"\033[1;35m"
# define CYAN		"\033[1;36m"
# define BOLD		"\033[1m\033[37m"
# define RESET		"\033[0m"

class BitcoinExchange {
	private:
		std::map<std::string, double> _DataBase;
		std::string _file;
		bool checkParsing(const std::string& line, std::string& date, double& value);
		bool validateDate(const std::string& date);
		bool isDateEarlier(const std::string& date1, const std::string& date2);

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		void readInputFile();
		void initializeDatabase();
		void setFileName(const std::string& fileName);
};

#endif