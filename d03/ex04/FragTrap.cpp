/* ************************************************************************** */
/*                                                                            */
/*    FragTrap.cpp           _             _              :::      ::::::::   */
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
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(void)
{
	srand(time(0));
	ClapTrap::setStats("FR4G-TP", 1, 100, 100, 100, 100, 30, 20, 5);
	std::cout << "FR4G-TP Default Constructor Called: [" << this->name << "] You're the wub to my dub!" << std::endl;
	return;
}

FragTrap::FragTrap(std::string name) 
{
	srand(time(0));
	ClapTrap::setStats(name, 1, 100, 100, 100, 100, 30, 20, 5);
	std::cout << "FR4G-TP Parameter Constructor Called: [" << this->name << "] The vault is... This way!" << std::endl;
	return;
}

FragTrap::FragTrap(FragTrap &obj)
{
	srand(time(0));
	*this = obj;
	std::cout << "FR4G-TP Copy Constructor Called: [" << this->name << "] You are ace high!" << std::endl;
	return;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FR4G-TP Destructor Called: [" << this->name << "] I'll die the way I lived: annoying!" << std::endl;
	return;
}

FragTrap &FragTrap::operator=(FragTrap const &r) 
{
	ClapTrap::operator=(r);
	std::cout << "Assigning Operator Called: [" << this->name << "] This time it'll be awesome, I promise!" << std::endl << std::endl;
	return (*this);
}

void	FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	int i = rand();
	int x = 0;

	void (FragTrap::*ptr[])(std::string const &) =
	{
		&FragTrap::meatUnicycle,
		&FragTrap::tripleClocked,
		&FragTrap::shhhhTrap,
		&FragTrap::rubberDucky,
		&FragTrap::senselessSacrifice
	};

	if (ClapTrap::getSp() < 25)
	{
		std::cout << "FR4G-TP " << this->name << " does not have enough energy points! Current energy " <<
			ClapTrap::getSp() << "/" << ClapTrap::getMsp() << std::endl << std::endl;
		return;
	}
	else
		ClapTrap::setSp(ClapTrap::getSp() - 25);
	std::cout << "FR4G-TP " << this->name << " uses VaultHunter.Exe! Let's see it's real powers!" << std::endl;
	i = (i % 5);
	while (x < 5)
	{
		if (x == i)
		{
			(this->*ptr[i])(target);
			x = 5;
		}
		x++;
	}
	return;
}

void	FragTrap::senselessSacrifice(std::string const &target)
{
	ClapTrap::setHp(0);
	std::cout << "FR4G-TP " << this->name << " uses Senseless Sacrifice! It sacrificed itself for it's friends... But there's no friends around!" <<
		std::endl << "Current Health: " << ClapTrap::getHp() << "/" << ClapTrap::getMhp() << std::endl
		<< "[" << this->name << "] For you...I commit...seddoku..." << std::endl << std::endl;
	return;
}

void	FragTrap::rubberDucky(std::string const &target)
{
	ClapTrap::setMhp(ClapTrap::getMhp() * 1.5);
	std::cout << "FR4G-TP " << this->name << " uses Rubber Ducky! With his rubber ducky his max health has increased by 1.5x!" << std::endl <<
		"New Max Health " << ClapTrap::getMhp() << std::endl
		<< "[" << this->name << "] Boiyoiyoiyoiyoing!" << std::endl << std::endl;
	return;
}

void	FragTrap::shhhhTrap(std::string const &target)
{
	ClapTrap::setArmor(ClapTrap::getArmor() * 5);
	std::cout << "FR4G-TP " << this->name << " uses Shhhh... Trap! By creative five clones it's armor has increased by 5x!" << std::endl <<
		"New Armor " << ClapTrap::getArmor() << std::endl
		<< "[" << this->name << "] Shoot him... he's the real one..." << std::endl << std::endl;
	return;
}

void	FragTrap::tripleClocked(std::string const &target)
{
	std::cout << "FR4G-TP " << this->name << " uses Triple Clocked! Ranged attack does 3x more damage!" << std::endl <<
		target << " takes " << ClapTrap::getRatk() * 3 << " damage!" << std::endl
		<< "[" << this->name << "] Kill, reload! Kill, reload! KILL! RELOAD!" << std::endl << std::endl;
	return;
}

void	FragTrap::meatUnicycle(std::string const &target)
{
	std::cout << "FR4G-TP " << this->name << " uses Meat Unicycle! Melee attack does 2x more damage!" << std::endl <<
		target << " takes " << ClapTrap::getPatk() * 2 << " damage!" << std::endl
		<< "[" << this->name << "] I have the shiniest meat bicycle!" << std::endl << std::endl;
	return;
}