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

ScavTrap::ScavTrap(void) : _hp(100), _mhp(100), _sp(50), _msp(50), _lvl(1), _name("SC4V-TP"), _patk(20), _ratk(15), _armor(3)
{
	srand(time(0));
	std::cout << "Default Constructor Called: [" << this->_name << "] It's about to get magical!" << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string name) : _hp(100), _mhp(100), _sp(50), _msp(50), _lvl(1), _name(name), _patk(20), _ratk(15), _armor(3)
{
	srand(time(0));
	std::cout << "Parameter Constructor Called: [" << this->_name << "] It's about to get magical!" << std::endl;
	return;
}

ScavTrap::ScavTrap(ScavTrap &obj)
{
	srand(time(0));
	*this = obj;
	std::cout << "Copy Constructor Called: [" << this->_name << "] I have an IDEA!" << std::endl;
	return;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor Called: [" << this->_name << "] Oh god I can't stop!" << std::endl;
	return;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &r) 
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
	std::cout << "Assigning Operator Called: [" << this->_name << "] You can call me Gundalf!" << std::endl << std::endl;
	return (*this);
}

void	ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << "SC4V-TP " << this->_name << " attacks " << target << 
		" at melee, causing " << this->_patk << " points of damage !" << std::endl << 
		"[" << this->_name << "] One for you, one for you, one for you!" << std::endl
		<< std::endl;
	return;
}

void	ScavTrap::rangedAttack(std::string const &target)
{
	std::cout << "SC4V-TP " << this->_name << " attacks " << target << 
		" at range, causing " << this->_ratk << " points of damage !" << std::endl << 
		"[" << this->_name << "] One shot, make it count!" << std::endl
		<< std::endl;
	return;
}

void	ScavTrap::rename(std::string input)
{
	std::cout << this->_name << " is being renamed, meet [" << input << "]!" << std::endl << std::endl;
	this->_name = input;
	return;
}

void	ScavTrap::displayStats()
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

void	ScavTrap::takeDamage(unsigned int amount)
{
	int i = 0;

	if (amount > (unsigned int)(this->_mhp + this->_armor))
		i = this->_mhp + this->_armor;
	else
		i = amount;
	this->_hp = this->_hp - i + this->_armor;
	if (this->_hp < 0)
		this->_hp = 0;
	std::cout << "SC4V-TP " << this->_name << " took " << amount << " of damage, armor blocked " << this->_armor << 
		" points of damage. It's current health is " << this->_hp << "/" << this->_mhp << std::endl;
	if (this->_hp == 0)
		std::cout << "[" << this->_name << "] Good, I didn't want any spare parts!" << std::endl << std::endl;
	else
		std::cout << "[" << this->_name << "] Here we go again!" << std::endl << std::endl;
	return;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	int healed = 0;

	if (amount > (unsigned int)this->_mhp)
		amount = (unsigned int)this->_mhp;
	if ((this->_hp + amount) > (unsigned int)this->_mhp)
	{
		healed = ((this->_hp + amount) - (unsigned int)this->_mhp) - amount;
		if (healed < 0)
			healed = healed * -1;
	}
	else
		healed = amount;
	this->_hp = this->_hp + amount;
	if (this->_hp > this->_mhp)
		this->_hp = this->_mhp;
	std::cout << "SC4V-TP " << this->_name << " recovers " << healed << " health back. Current health is "  <<
		this->_hp << "/" << this->_mhp << std::endl <<
		"[" << this->_name << "] Hahaha... I ascend!" << std::endl << std::endl;
	return;
}

void	ScavTrap::challengeNewcomer(void)
{
	int i = rand();
	
	std::cout << "[" << this->_name << "]" << " challenges the newcomer to ";
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
