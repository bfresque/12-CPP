/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:27:11 by bfresque          #+#    #+#             */
/*   Updated: 2024/01/31 12:16:09 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;

int	Account::_totalAmount = 0;

int	Account::_totalNbDeposits = 0;

int	Account::_totalNbWithdrawals = 0;

Account::Account (int depot)
{
	this->_accountIndex = this->getNbAccounts();
	this->_amount = depot;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += depot;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";created" << std::endl;
	Account::_nbAccounts++;
	return;
}

Account::~Account ()
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";closed" << std::endl;
	Account::_nbAccounts--;
	return;
}

// I prefer mine, but if I have to take yours, I will !
void	Account::_displayTimestamp(void)
{
	time_t	t;

	t = time(NULL);
	std::cout << std::put_time(localtime(&t), "[%Y%m%d_%H%M%S] ");
}

// void	Account::_displayTimestamp(void)
// {
// 	time_t now = time(NULL);

// 	// Convertir en format local
// 	std::tm *ltm = std::localtime(&now);

// 	// Buffer pour stocker la date et l'heure
// 	char buffer[80];
// 	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", ltm);

// 	std::cout << buffer;

// 	return ;
// }

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

///////////////////////////////////////////////////////////////

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "account:" << Account::getNbAccounts();
	std::cout << ";total:" << Account::getTotalAmount();
	std::cout << ";deposit:" << Account::getNbDeposits();
	std::cout << ";withdrawals:" << Account::getNbWithdrawals();
	std::cout << std::endl;
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	std::cout << ";deposits:" << deposit;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";deposits:" << this->_nbDeposits;;
	std::cout << std::endl;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal < this->_amount)
	{
		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex;
		std::cout << ";p_amount:" << this->_amount;
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		std::cout << ";withdrawal:" << withdrawal;
		std::cout << ";amount:" << this->checkAmount();
		std::cout << ";withdrawal:" << this->_nbWithdrawals;;
		std::cout << std::endl;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		return (true);
	}
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->checkAmount();
	std::cout << ";withdrawal:refused" << std::endl;
	return (false);
}
