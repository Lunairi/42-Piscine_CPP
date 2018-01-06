/* ************************************************************************** */
/*                                                                            */
/*    HumanA.cpp             _             _              :::      ::::::::   */
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
#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string nick, Weapon &var) : name(nick), wep(var)
{
	return;
}

HumanA::~HumanA(void) 
{
	return;
}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with his " << this->wep.getType() << std::endl;
	return;
}
