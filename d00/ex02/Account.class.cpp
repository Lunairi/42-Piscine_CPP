/* ************************************************************************** */
/*                                                                            */
/*    Account.class.cpp      _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include "Account.class.hpp"

Account::Account(int initial_deposit)
{
	this->_nbAccounts = this->_nbAccounts + 1;
	this->_totalAmount = this->_totalAmount + initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = this->_nbAccounts;
	this->_amount = initial_deposit;

	std::cout << "[";
	_displayTimestamp();
	std::cout << "] index:" << (this->_accountIndex - 1) <<
		";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(void)
{
	std::cout << "[";
	_displayTimestamp();
	std::cout << "] index:" << (this->_accountIndex - 1) <<
		";amount:" << this->_amount << ";closed" << std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t	timev = time(&timev);
	struct tm *stamp = localtime(&timev);

	std::cout << (1900 + stamp->tm_year);
	if (stamp->tm_mon >= 9)
		std::cout << (stamp->tm_mon + 1);
	else
		std::cout << "0" << (stamp->tm_mon + 1);
	if (stamp->tm_mday > 9)
		std::cout << stamp->tm_mday;
	else
		std::cout << "0" << (stamp->tm_mday);
	if (stamp->tm_hour > 9)
		std::cout << "_" << stamp->tm_hour;
	else
		std::cout << "_0" << stamp->tm_hour;
	if (stamp->tm_min > 9)
		std::cout << stamp->tm_min;
	else
		std::cout << "0" << stamp->tm_min;
	if (stamp->tm_sec > 9)
		std::cout << stamp->tm_sec;
	else
		std::cout << "0" << stamp->tm_sec;
	return ;
}

void	Account::displayAccountsInfos(void)
{
	std::cout << "[";
	_displayTimestamp();
	std::cout << "] accounts:" << _nbAccounts <<
		";total:" << _totalAmount <<
		";deposits:" << _totalNbDeposits <<
		";withdrawals:" << _totalNbWithdrawals <<
		std::endl;
}

void		Account::displayStatus(void) const
{
	std::cout << "[";
	_displayTimestamp();
	std::cout << "] index:" << (this->_accountIndex - 1) <<
		";amount:" << this->_amount << ";deposits:" << this->_nbDeposits <<
		";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void		Account::makeDeposit(int deposit)
{
	this->_amount = this->_amount + deposit;
	this->_nbDeposits = this->_nbDeposits + 1;
	this->_totalAmount = this->_totalAmount + deposit;
	this->_totalNbDeposits = this->_totalNbDeposits + 1;

	std::cout << "[";
	_displayTimestamp();
	std::cout << "] index:" << (this->_accountIndex - 1) << ";p_amount:" << (this->_amount - deposit) << 
		";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool		Account::makeWithdrawal(int withdrawal)
{
	if (this->_amount < withdrawal)
	{
		std::cout << "[";
		_displayTimestamp();
		std::cout << "] index:" << (this->_accountIndex - 1) << 
			";p_amount:" << this->_amount <<  ";withdrawal:" << "refused" << std::endl;
		return (false);
	}
	else
	{
		this->_totalAmount = this->_totalAmount - withdrawal;
		this->_totalNbWithdrawals = this->_totalNbWithdrawals + 1;
		this->_amount = this->_amount - withdrawal;
		this->_nbWithdrawals = this->_nbWithdrawals + 1;
		std::cout << "[";
		_displayTimestamp();
		std::cout << "] index:" << (this->_accountIndex - 1) << 
			";p_amount:" << (this->_amount + withdrawal) <<  ";withdrawal:" <<
			withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
}

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;