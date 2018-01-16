/* ************************************************************************** */
/*                                                                            */
/*    CentralBureaucracy.cpp _             _              :::      ::::::::   */
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
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "CentralBureaucracy.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "OfficeBlock.hpp"

CentralBureaucracy::CentralBureaucracy(void)
{
	srand(time(0));
	Intern whocares;

	int i = 0;

	while (i < 20)
	{
		_ob[i].setIntern(whocares);
		i++;
	}
	return;
}

// CentralBureaucracy::CentralBureaucracy(CentralBureaucracy &src)
// {
// 	*this = src;
// 	return;
// }

CentralBureaucracy::~CentralBureaucracy(void)
{
	return;
}

void	CentralBureaucracy::doBureaucracy(void)
{
	int i = 0;
	int x = 0;

	std::string input[] =
	{
		"Shrubbery Creation",
		"Presidential Pardon",
		"Robotomy Request"
	};

	if (_target[0] == "")
	{
		std::cout << "No targets queue'd, no bureaucracy stuff being done" << std::endl;
		return;
	}
	while (_target[i] != "")
	{
		x = rand() % 20;
		if (_ob[x].getAll() == 1)
		{
			_ob[x].doBureaucracy(input[x % 3], _target[i]);
			i++;
			std::cout << std::endl;
		}
	}
	std::cout << std::endl << "Completed all bureaucracy stuff" << std::endl;
}

void	CentralBureaucracy::feedSigner(Bureaucrat &obj)
{
	int i = 0;

	while (i < 20)
	{
		if (_ob[i].getSigner() == 0)
		{
			_ob[i].setSigner(obj);
			return;
		}
		i++;
	}
	std::cout << "Central Bureaucracy is full, cannot add more Signers" << std::endl;
	return;
}

void	CentralBureaucracy::feedExecuter(Bureaucrat &obj)
{
	int i = 0;

	while (i < 20)
	{
		if (_ob[i].getExecuter() == 0)
		{
			_ob[i].setExecutor(obj);
			return;
		}
		i++;
	}
	std::cout << "Central Bureaucracy is full, cannot add more Executer" << std::endl;
	return;
}

void	CentralBureaucracy::queueUp(std::string obj)
{
	int i = 0;

	while (i < 100)
	{
		if (_target[i] == "")
		{
			_target[i] = obj;
			return;
		}
		i++;
	}
	std::cout << "Only 100 targets can be queue'd" << std::endl;
	return;
}

