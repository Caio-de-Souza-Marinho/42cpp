/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:01:06 by caide-so          #+#    #+#             */
/*   Updated: 2025/10/14 07:58:31 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	std::cout << " index:" << _accountIndex 
		<< ";amount:" << _amount 
		<< ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex 
		<< ";amount:" << _amount 
		<< ";closed" << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t	now = std::time(NULL);
	std::tm		*timeinfo = std::localtime(&now);
	char		buffer[20];

	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", timeinfo);
	std::cout << buffer;
}
