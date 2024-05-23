/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:01:08 by bfresque          #+#    #+#             */
/*   Updated: 2024/05/23 09:41:16 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

void BitcoinExchange::setFileName(const std::string& fileName) {
	this->_file = fileName;
}

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
		return (1);
	}
	BitcoinExchange btcExchange;
	btcExchange.initializeDatabase();
	btcExchange.setFileName(argv[1]);

	try {
		btcExchange.readInputFile();
	}
	catch (const std::exception& e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
		return (1);
	}
	return (0);
}