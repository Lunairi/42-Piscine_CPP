/* ************************************************************************** */
/*                                                                            */
/*    Character.cpp              _             _              :::      ::::::::   */
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
#include "Character.hpp"

Character::Character(std::string const &name) : _name(name), _weapon(NULL), _ap(40)
{
	return;
}

Character::Character(Character &obj)
{
	*this = obj;
	return;
}

Character::~Character(void)
{
	return;
}

Character &Character::operator=(Character const &r) 
{
	this->_name = r._name;
	this->_weapon = r._weapon;
	this->_ap = r._ap;
	return (*this);
}

std::string		Character::getName(void) const
{
	return (this->_name);
}

int				Character::getAP(void) const
{
	return (this->_ap);
}

AWeapon			*Character::getWeapon(void) const
{
	return (this->_weapon);
}

void			Character::recoverAP(void)
{
	this->_ap = this->_ap + 10;
	if (this->_ap > 40)
		this->_ap = 40;
}

void			Character::equip(AWeapon *weapon)
{
	this->_weapon = weapon;
	return;
}

void			Character::attack(Enemy *enemy)
{
	if(!enemy->getHP())
		return;
	if (this->_weapon)
	{
		if (this->_ap != 0 && (this->_ap >= this->_weapon->getAPCost()))
		{
			std::cout << this->_name << " attacks " << enemy->getType() << " with a " << this->_weapon->getName() << std::endl;
			this->_weapon->attack();
			enemy->takeDamage(this->_weapon->getDamage());
			this->_ap = this->_ap - this->_weapon->getAPCost();
			if (enemy->getHP() <= 0)
				delete enemy;
		}
	}
	return;
}

std::ostream	&operator<<(std::ostream &o, Character const &r)
{
	if (r.getWeapon())
		o << r.getName() << " has " << r.getAP() << " AP and wields a " << r.getWeapon()->getName() << std::endl;
	else
		o << r.getName() << " has " << r.getAP() << " AP and is unarmed" << std::endl;
	return (o);
}