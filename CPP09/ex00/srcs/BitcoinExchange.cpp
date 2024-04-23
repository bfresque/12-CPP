/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:24:16 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/22 16:35:19 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

bool BitcoinExchange::isDateEarlier(const std::string& date1, const std::string& date2) {
	std::tm time1 = {};
	std::tm time2 = {};

	if (strptime(date1.c_str(), "%Y-%m-%d", &time1) == NULL ||
		strptime(date2.c_str(), "%Y-%m-%d", &time2) == NULL)
		return(false);

	return (std::mktime(&time1) < std::mktime(&time2));
}

bool BitcoinExchange::validateDate(const std::string& date) {
	
	if (date.length() != 10)
		return (false);
	
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8);
	
	for (size_t i = 0; i < year.length(); i++) {
		if (!isdigit(year[i]))
			return (false);
	}

	for (size_t i = 0; i < month.length(); i++) {
		if (!isdigit(month[i]))
			return (false);
	}

	for (size_t i = 0; i < day.length(); i++) {
		if (!isdigit(day[i]))
			return (false);
	}
	
	int yvalue = atoi(year.c_str());
	int mvalue = atoi(month.c_str());
	int dvalue = atoi(day.c_str());

	if (yvalue < 2009)
		return (false);

	if (mvalue < 1 || mvalue > 12)
		return (false);

	if (dvalue < 1 || dvalue > 31)
		return (false);

	return (true);
}

bool BitcoinExchange::checkParsing(const std::string& line, std::string& date, double& value) {
	size_t pos = line.find('|');
	if (pos == std::string::npos) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return (false);
	}

	date = line.substr(0, pos - 1);
	std::string valueStr = line.substr(pos + 2);

	if (!this->validateDate(date)) {
		std::cerr << "Error: bad input => " << date << std::endl;
		return (false);
	}

	char* end;
	value = std::strtod(valueStr.c_str(), &end);
	if (*end != '\0') {
		std::cerr << "Error: value is not a number." << std::endl;
		return (false);
	}

	if (value < 0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return (false);
	}

	if (value > 1000) {
		std::cerr << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
}

void BitcoinExchange::readInputFile() {
	std::ifstream inputFile(this->_file.c_str());
	if (!inputFile.is_open())
		throw std::runtime_error("Error: couldn't open input file.");

	std::string line;
	std::getline(inputFile, line);

	while (std::getline(inputFile, line)) {
		if (line.empty() || line == "date | value")
			continue;

		std::string date;
		double num;
		if (this->checkParsing(line, date, num)) {
			if (this->_DataBase.find(date) != this->_DataBase.end())
				std::cout << date << " => " << num << " = " << num * this->_DataBase[date] << std::endl;
			else {
				std::string closest_date = this->_DataBase.begin()->first;
				for (std::map<std::string, double>::iterator it = this->_DataBase.begin(); it != this->_DataBase.end(); ++it) {
					if (isDateEarlier(it->first, date))
						closest_date = it->first;
					else
						break;
				}
				double result = num * this->_DataBase[closest_date];
				std::cout << date << " => " << num << " = " << result << std::endl;
			}
		}
	}
}

void BitcoinExchange::initializeDatabase() {
	std::ifstream dataFile("data.csv");
	if (!dataFile.is_open())
		throw std::runtime_error("Error: couldn't open database file.");

	std::string line;
	std::getline(dataFile, line);
	while (std::getline(dataFile, line)) {
		if (line.length() < 12) {
			std::cerr << "Warning: Skipping malformed line in data.csv: " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0,10);
		double rate = atof(line.substr(11).c_str());
		this->_DataBase[date] = rate;
	}
	dataFile.close();
}