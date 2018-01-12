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

FragTrap::FragTrap(void) : _hp(100), _mhp(100), _sp(100), _msp(100), _lvl(1), _name("FR4G-TP"), _patk(30), _ratk(20), _armor(5)
{
	srand(time(0));
	std::cout << "Default Constructor Called: [" << this->_name << "] You're the wub to my dub!" << std::endl;
	return;
}

FragTrap::FragTrap(std::string name) : _hp(100), _mhp(100), _sp(100), _msp(100), _lvl(1), _name(name), _patk(30), _ratk(20), _armor(5)
{
	srand(time(0));
	std::cout << "Parameter Constructor Called: [" << this->_name << "] The vault is... This way!" << std::endl;
	return;
}

FragTrap::FragTrap(FragTrap &obj)
{
	srand(time(0));
	*this = obj;
	std::cout << "Copy Constructor Called: [" << this->_name << "] You are ace high!" << std::endl;
	return;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor Called: [" << this->_name << "] I'll die the way I lived: annoying!" << std::endl;
	return;
}

FragTrap &FragTrap::operator=(FragTrap const &r) 
{
	this->_name = r._name;
	this->_lvl = r._lvl;
	this->_hp = r._hp;
	this->_mhp = r._mhp;
	this->_sp = r._sp;
	this->_msp = r._msp;
	this->_patk = r._patk;
	this->_ratk = r._ratk;
	this->_armor = r._armor;
	std::cout << "Assigning Operator Called: [" << this->_name << "] This time it'll be awesome, I promise!" << std::endl << std::endl;
	return (*this);
}

void	FragTrap::meleeAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << 
		" at melee, causing " << this->_patk << " points of damage !" << std::endl << 
		"[" << this->_name << "] That looks like it hurts!" << std::endl
		<< std::endl;
	return;
}

void	FragTrap::rangedAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << 
		" at range, causing " << this->_ratk << " points of damage !" << std::endl << 
		"[" << this->_name << "] Oh, quit falling to pieces." << std::endl
		<< std::endl;
	return;
}

void	FragTrap::rename(std::string input)
{
	std::cout << this->_name << " is being renamed, meet [" << input << "]!" << std::endl << std::endl;
	this->_name = input;
	return;
}

void	FragTrap::displayStats()
{
	std::cout << this->_name << " stats:" << std::endl <<
		"Level: " << this->_lvl << std::endl <<
		"Health: " << this->_hp << "/" << this->_mhp << std::endl <<
		"Energy: " << this->_sp << "/" << this->_msp << std::endl <<
		"Melee Attack: " << this->_patk << std::endl <<
		"Ranged Attack: " << this->_ratk << std::endl <<
		"Armor: " << this->_armor << std::endl << std::endl;
	return;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	int i = 0;

	if (amount > (unsigned int)(this->_mhp + this->_armor))
		i = this->_mhp + this->_armor;
	else
		i = amount;
	this->_hp = this->_hp - i + this->_armor;
	if (this->_hp < 0)
		this->_hp = 0;
	std::cout << "FR4G-TP " << this->_name << " took " << amount << " of damage, armor blocked " << this->_armor << 
		" points of damage. It's current health is " << this->_hp << "/" << this->_mhp << std::endl;
	if (this->_hp == 0)
		std::cout << "[" << this->_name << "] The robot is dead, long live the robot!" << std::endl << std::endl;
	else
		std::cout << "[" << this->_name << "] Why do I even feel pain?" << std::endl << std::endl;
	return;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	int healed = 0;

	if (amount > (unsigned int)this->_mhp)
		amount = (unsigned int)this->_mhp;
	if ((this->_hp + amount) > (unsigned int)this->_mhp)
	{
		healed = ((this->_hp + amount) - this->_mhp) - amount;
		if (healed < 0)
			healed = healed * -1;
	}
	else
		healed = amount;
	this->_hp = this->_hp + amount;
	if (this->_hp > this->_mhp)
		this->_hp = this->_mhp;
	std::cout << "FR4G-TP " << this->_name << " recovers " << healed << " health back. Current health is "  <<
		this->_hp << "/" << this->_mhp << std::endl <<
		"[" << this->_name << "] Sweet life juice!" << std::endl << std::endl;
	return;
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

	if (this->_sp < 25)
	{
		std::cout << "FR4G-TP " << this->_name << " does not have enough energy points! Current energy " <<
			this->_sp << "/" << this->_msp << std::endl << std::endl;
		return;
	}
	else
		this->_sp = this->_sp - 25;
	std::cout << "FR4G-TP " << this->_name << " uses VaultHunter.Exe! Let's see it's real powers!" << std::endl;
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
	(void)target;
	this->_hp = 0;
	std::cout << "FR4G-TP " << this->_name << " uses Senseless Sacrifice! It sacrificed itself for it's friends... But there's no friends around!" <<
		std::endl << "Current Health: " << this->_hp << "/" << this->_mhp << std::endl
		<< "[" << this->_name << "] For you...I commit...seddoku..." << std::endl << std::endl;
	return;
}

void	FragTrap::rubberDucky(std::string const &target)
{
	(void)target;
	this->_mhp = this->_mhp * 1.5;
	std::cout << "FR4G-TP " << this->_name << " uses Rubber Ducky! With his rubber ducky his max health has increased by 1.5x!" << std::endl <<
		"New Max Health " << this->_mhp << std::endl
		<< "[" << this->_name << "] Boiyoiyoiyoiyoing!" << std::endl << std::endl;
	return;
}

void	FragTrap::shhhhTrap(std::string const &target)
{
	(void)target;
	this->_armor = this->_armor * 5;
	std::cout << "FR4G-TP " << this->_name << " uses Shhhh... Trap! By creative five clones it's armor has increased by 5x!" << std::endl <<
		"New Armor " << this->_armor << std::endl
		<< "[" << this->_name << "] Shoot him... he's the real one..." << std::endl << std::endl;
	return;
}

void	FragTrap::tripleClocked(std::string const &target)
{
	std::cout << "FR4G-TP " << this->_name << " uses Triple Clocked! Ranged attack does 3x more damage!" << std::endl <<
		target << " takes " << this->_ratk * 3 << " damage!" << std::endl
		<< "[" << this->_name << "] Kill, reload! Kill, reload! KILL! RELOAD!" << std::endl << std::endl;
	return;
}

void	FragTrap::meatUnicycle(std::string const &target)
{
	std::cout << "FR4G-TP " << this->_name << " uses Meat Unicycle! Melee attack does 2x more damage!" << std::endl <<
		target << " takes " << this->_patk * 2 << " damage!" << std::endl
		<< "[" << this->_name << "] I have the shiniest meat bicycle!" << std::endl << std::endl;
	return;
}