/* ************************************************************************** */
/*                                                                            */
/*    Ice.cpp                _             _              :::      ::::::::   */
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
#include "Ice.hpp"

Ice::Ice(std::string const &type) : AMateria(type)
{
	return;
}

Ice::Ice(Ice &obj)
{
	*this = obj;
	return;
}

Ice::~Ice(void)
{
	return;
}

Ice &Ice::operator=(Ice const &r) 
{
// 	setType(r.getType());
// 	setXP(r.getXP());
	(void)r;
	return (*this);
}

Ice*	Ice::clone(void) const
{
	Ice 	*ice = new Ice("Ice");

	return (ice);
}

void		Ice::use(ICharacter &target)
{
	increaseXP();
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}