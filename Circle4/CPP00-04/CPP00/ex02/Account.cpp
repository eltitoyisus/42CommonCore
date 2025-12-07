/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:12:09 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/26 19:12:09 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0; 
int Account::_totalNbWithdrawals = 0;

// CONSTRUCTOR
Account::Account(int initial_deposit) 
	: _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_totalAmount += initial_deposit;
	_totalNbDeposits = 0;
	_totalNbWithdrawals = 0;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "created"
				<< std::endl;
}

// Deposit | Withdrawal
void Account::makeDeposit(int deposit)
{
	int p_amount = _amount;

	_amount += deposit; 
	_nbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "p_amount:" << p_amount << ";"
				<< "deposit:" << deposit << ";"
				<< "amount:" << _amount << ";"
				<< "nb_deposits:" << _nbDeposits
				<< std::endl;
	_totalNbDeposits += _nbDeposits;
	_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	int p_amount = _amount;

	if (withdrawal > _amount)
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";" 
					<< "p_amount:" << p_amount << ";"
					<< "withdrawal:refused" 
					<< std::endl;
		return false;
	}
	else
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";"
					<< "p_amount:" << p_amount << ";"
					<< "withdrawal:" << withdrawal << ";"
					<< "amount:" << _amount << ";"
					<< "nb_withdrawals:" << _nbWithdrawals
					<< std::endl;
		_totalNbWithdrawals += _nbWithdrawals;
		_totalAmount -= withdrawal;
		return true;
	}
}

// GETTERS
int Account::checkAmount(void) const
{
	return this->_amount;
}

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}


int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}


// Write output

void Account::_displayTimestamp(void)
{
	time_t rawtime;
	struct tm *timeinfo;
	char buffer[18];

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, 18, "[%Y%m%d_%H%M%S]", timeinfo);
	std::cout << buffer << " ";
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "deposits:" << _nbDeposits << ";"
				<< "withdrawals:" << _nbWithdrawals
				<< std::endl;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";"
				<< "total:" << _totalAmount << ";"
				<< "deposits:" << _totalNbDeposits << ";"
				<< "withdrawals:" << _totalNbWithdrawals 
				<< std::endl;
}

// DESTRUCTOR
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "closed" 
				<< std::endl;
}
