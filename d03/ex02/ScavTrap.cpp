/* ************************************************************************** */
/*                                                                            */
/*    ScavTrap.cpp           _             _              :::      ::::::::   */
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
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(void)
{
	srand(time(0));
	ClapTrap::setStats("SC4V-TP", 1, 100, 100, 50, 50, 20, 15, 3);
	std::cout << "SC4V-TP Default Constructor Called: [" << this->name << "] It's about to get magical!" << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string name)
{
	srand(time(0));
	ClapTrap::setStats(name, 1, 100, 100, 50, 50, 20, 15, 3);
	std::cout << "SC4V-TP Parameter Constructor Called: [" << this->name << "] It's about to get magical!" << std::endl;
	return;
}

ScavTrap::ScavTrap(ScavTrap &obj)
{
	srand(time(0));
	*this = obj;
	std::cout << "SC4V-TP Copy Constructor Called: [" << this->name << "] I have an IDEA!" << std::endl;
	return;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "SC4V-TP estructor Called: [" << this->name << "] Oh god I can't stop!" << std::endl;
	return;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &r) 
{
	ClapTrap::operator=(r);
	std::cout << "Assigning Operator Called: [" << this->name << "] You can call me Gundalf!" << std::endl << std::endl;
	return (*this);
}

void	ScavTrap::challengeNewcomer(void)
{
	int i = rand();
	
	std::cout << "[" << this->name << "]" << " challenges the newcomer to ";
	if (i % 5 == 0)
		std::cout << "russian roulette! What's the worst that can happen to the newcomer? More specifically, what's the worse that could happen to ScavTrap since it's made of, you know... junk?"
		<< std::endl << std::endl;
	else if (i % 5 == 1)
		std::cout << "doing wheelies on a meat bicycle! Perfectly kosher, and to a certain degree a bit delicious if you think about it."
		<< std::endl << std::endl;
	else if (i % 5 == 2)
		std::cout << "DANCE PARTY! Get your groove on and let's see who can twerk and shake those hips the best!"
		<< std::endl << std::endl;
	else if (i % 5 == 3)
		std::cout << "friendly duel, don't worry because you're a newcomer you are guaranteed to lose, watch my karate moves! Hyah!"
		<< std::endl << std::endl;
	else if (i % 5 == 4)
		std::cout << "non stop loot box addiction! Let's see who can open the most loot box before our wallets are empty!"
		<< std::endl << std::endl;
}
