/* ************************************************************************** */
/*                                                                            */
/*    HumanB.cpp             _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>
#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string nick) : name(nick)
{
	return;
}

HumanB::~HumanB(void) 
{
	return;
}

void	HumanB::attack()
{
	std::cout << this->name << " attacks with his " << this->wep->getType() << std::endl;
	return;
}

void	HumanB::setWeapon(Weapon &var)
{
	this->wep = &var;
	return;
}