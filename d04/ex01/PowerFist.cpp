/* ************************************************************************** */
/*                                                                            */
/*    PowerFist.cpp           _             _              :::      ::::::::   */
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
#include "PowerFist.hpp"

PowerFist::PowerFist(void) : AWeapon("Power First", 8, 50)
{
	return;
}

PowerFist::PowerFist(PowerFist &obj) : AWeapon(obj)
{
	*this = obj;
	return;
}

PowerFist::~PowerFist(void)
{
	return;
}

PowerFist &PowerFist::operator=(PowerFist const &r) 
{
	AWeapon::operator=(r);
	return (*this);
}

void	PowerFist::attack(void)
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
	return;
}