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
	//std::cout << "[19920104_091532]";
}

int	Account::getNbAccounts()
{
	return (_nbAccounts);
}

int	Account::getTotalAmount()
{
	return (_totalAmount);
}

int	Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts()
		<< ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals()
		<< std::endl;
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex 
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals
		<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << " index:" << _accountIndex 
		<< ";p_amount:" << _amount - deposit
		<< ";deposit:" << deposit
		<< ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits
		<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal <= checkAmount())
	{
		_displayTimestamp();
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << " index:" << _accountIndex 
			<< ";p_amount:" << _amount + withdrawal
			<< ";withdrawal:" << withdrawal
			<< ";amount:" << _amount
			<< ";nb_withdrawals:" << _nbWithdrawals
			<< std::endl;
		return (true);
	}
	_displayTimestamp();
	std::cout << " index:" << _accountIndex 
		<< ";p_amount:" << _amount
		<< ";withdrawal:refused"
		<< std::endl;
	return (false);
}

int	Account::checkAmount() const
{
	return (_amount);
}
