/* ************************************************************************** */
/*                                                                            */
/*    SuperTrap.cpp           _             _              :::      ::::::::   */
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
#include "SuperTrap.hpp"
#include "ClapTrap.hpp"

SuperTrap::SuperTrap(void) : ClapTrap(), FragTrap(), NinjaTrap()
{
	srand(time(0));
	ClapTrap::setStats("SP3R-TP", 1, 100, 100, 120, 120, 60, 20, 5);
	std::cout << "SP3R-TP Default Constructor Called: [" << this->name << "] I'm like Brick on steroids!" << std::endl;
	return;
}

SuperTrap::SuperTrap(std::string name) : ClapTrap(name), FragTrap(name), NinjaTrap(name)
{
	srand(time(0));
	ClapTrap::setStats(name, 1, 100, 100, 120, 120, 60, 20, 5);
	std::cout << "SP3R-TP Parameter Constructor Called: [" << this->name << "] I'm like Brick on steroids!" << std::endl;
	return;
}

SuperTrap::SuperTrap(SuperTrap &obj) : ClapTrap(obj), FragTrap(obj), NinjaTrap(obj)
{
	srand(time(0));
	*this = obj;
	std::cout << "SP3R-TP Copy Constructor Called: [" << this->name << "] I'm a copy just like Lilith!" << std::endl;
	return;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << "SP3R-TP Destructor Called: [" << this->name << "] Oh god I'm dead like Roland!" << std::endl;
	return;
}

SuperTrap &SuperTrap::operator=(SuperTrap const &r)
{
	ClapTrap::operator=(r);
	std::cout << "Assigning Operator Called: [" << this->name << "] I'm a deadeye like Mordecai!" << std::endl << std::endl;
	return (*this);
}

