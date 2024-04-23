/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:32:45 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/22 16:36:14 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BitcoinExchange_HPP
# define BitcoinExchange_HPP

# include <iostream>
# include <map>
# include <fstream>

class BitcoinExchange {
	private:
		std::map<std::string, double> _DataBase;
		std::string _file;
		bool checkParsing(const std::string& line, std::string& date, double& value);
		bool validateDate(const std::string& date);
		bool isDateEarlier(const std::string& date1, const std::string& date2);

	public:
		void readInputFile();
		void initializeDatabase();
		void setFileName(const std::string& fileName);
};

#endif