/* ************************************************************************** */
/*                                                                            */
/*    SuperMutant.cpp        _             _              :::      ::::::::   */
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
#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void) : Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
	return;
}

SuperMutant::SuperMutant(SuperMutant &obj) : Enemy(obj)
{
	*this = obj;
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
	return;
}

SuperMutant::~SuperMutant(void)
{
	std::cout << "Aaargh ..." << std::endl;
	return;
}

SuperMutant &SuperMutant::operator=(SuperMutant const &r) 
{
	Enemy::operator=(r);
	return (*this);
}

void			SuperMutant::takeDamage(int amount)
{
	int i = 0;

	if (amount < 3)
		return;
	else if (amount > (this->getHP() + 3) )
		i = this->getHP() + 3;
	else
		i = amount;
	this->setHP(this->getHP() - i + 3);
	if (this->getHP() < 0)
		this->setHP(0);
	return;
}