/* ************************************************************************** */
/*                                                                            */
/*    ClapTrap.cpp           _             _              :::      ::::::::   */
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
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("CL4P-TP"), _hp(100), _mhp(100), _sp(100), _msp(100), _lvl(1), _patk(30), _ratk(20), _armor(5)
{
	srand(time(0));
	std::cout << "CL4P-TP Default Constructor Called: [" << this->name << "] Welcome Vault Hunters!" << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name) : name(name), _hp(100), _mhp(100), _sp(100), _msp(100), _lvl(1), _patk(30), _ratk(20), _armor(5)
{
	srand(time(0));
	std::cout << "CL4P-TP Parameter Constructor Called: [" << this->name << "] Welcome Vault Hunters!" << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap &obj)
{
	srand(time(0));
	*this = obj;
	std::cout << "CL4P-TP Copy Constructor Called: [" << this->name << "] I am so impressed with myself!" << std::endl;
	return;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "CL4P-TP Destructor Called: [" << this->name << "] Who'se a badass robot? This guy!" << std::endl;
	return;
}

void	ClapTrap::setStats(std::string name, int lvl, int hp, int mhp, int sp, int msp, int patk, int ratk, int armor)
{
	this->name = name;
	this->_lvl = lvl;
	this->_hp = hp;
	this->_mhp = mhp;
	this->_sp = sp;
	this->_msp = msp;
	this->_patk = patk;
	this->_ratk = ratk;
	this->_armor = armor;
	return;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &r) 
{
	this->name = r.name;
	this->_lvl = r._lvl;
	this->_hp = r._hp;
	this->_mhp = r._mhp;
	this->_sp = r._sp;
	this->_msp = r._msp;
	this->_patk = r._patk;
	this->_ratk = r._ratk;
	this->_armor = r._armor;
	std::cout << "Assigning Operator Called: [" << this->name << "] This time it'll be awesome, I promise!" << std::endl << std::endl;
	return (*this);
}

void	ClapTrap::meleeAttack(std::string const &target)
{
	std::cout << "CL4P-TP " << this->name << " attacks " << target << 
		" at melee, causing " << this->_patk << " points of damage !" << std::endl << 
		"[" << this->name << "] That looks like it hurts!" << std::endl
		<< std::endl;
	return;
}

void	ClapTrap::rangedAttack(std::string const &target)
{
	std::cout << "CL4P-TP " << this->name << " attacks " << target << 
		" at range, causing " << this->_ratk << " points of damage !" << std::endl << 
		"[" << this->name << "] Oh, quit falling to pieces." << std::endl
		<< std::endl;
	return;
}

void	ClapTrap::rename(std::string input)
{
	std::cout << this->name << " is being renamed, meet [" << input << "]!" << std::endl << std::endl;
	this->name = input;
	return;
}

void	ClapTrap::displayStats()
{
	std::cout << this->name << " stats:" << std::endl <<
		"Level: " << this->_lvl << std::endl <<
		"Health: " << this->_hp << "/" << this->_mhp << std::endl <<
		"Energy: " << this->_sp << "/" << this->_msp << std::endl <<
		"Melee Attack: " << this->_patk << std::endl <<
		"Ranged Attack: " << this->_ratk << std::endl <<
		"Armor: " << this->_armor << std::endl << std::endl;
	return;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	int i = 0;

	if (amount > (unsigned int)(this->_mhp + this->_armor))
		i = this->_mhp + this->_armor;
	else
		i = amount;
	this->_hp = this->_hp - i + this->_armor;
	if (this->_hp < 0)
		this->_hp = 0;
	std::cout << "CL4P-TP " << this->name << " took " << amount << " of damage, armor blocked " << this->_armor << 
		" points of damage. It's current health is " << this->_hp << "/" << this->_mhp << std::endl;
	if (this->_hp == 0)
		std::cout << "[" << this->name << "] The robot is dead, long live the robot!" << std::endl << std::endl;
	else
		std::cout << "[" << this->name << "] Why do I even feel pain?" << std::endl << std::endl;
	return;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	int healed = 0;

	if (amount > (unsigned int)this->_mhp)
		amount = this->_mhp;
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
	std::cout << "CL4P-TP " << this->name << " recovers " << healed << " health back. Current health is "  <<
		this->_hp << "/" << this->_mhp << std::endl <<
		"[" << this->name << "] Sweet life juice!" << std::endl << std::endl;
	return;
}

void	ClapTrap::setHp(int i)
{
	this->_hp = i;
	return;
}

void	ClapTrap::setMhp(int i)
{
	this->_mhp = i;
	return;
}

void	ClapTrap::setArmor(int i)
{
	this->_armor = i;
	return;
}

void	ClapTrap::setSp(int i)
{
	this->_sp = i;
	return;
}

int		ClapTrap::getHp(void)
{
	return (this->_hp);
}

int		ClapTrap::getMhp(void)
{
	return (this->_mhp);
}

int		ClapTrap::getSp(void)
{
	return (this->_sp);
}

int		ClapTrap::getMsp(void)
{
	return (this->_msp);
}

int		ClapTrap::getLvl(void)
{
	return (this->_lvl);
}

int		ClapTrap::getPatk(void)
{
	return (this->_patk);
}

int		ClapTrap::getRatk(void)
{
	return (this->_ratk);
}

int		ClapTrap::getArmor(void)
{
	return (this->_armor);
}