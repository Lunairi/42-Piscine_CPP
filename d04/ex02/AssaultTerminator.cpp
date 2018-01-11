/* ************************************************************************** */
/*                                                                            */
/*    AssaultTerminator.cpp  _             _              :::      ::::::::   */
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
#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator(void)
{
	std::cout << "* teleports from space *" << std::endl;
	return;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const &obj)
{
	*this = obj;
	std::cout << "* teleports from space *" << std::endl;
	return;
}

AssaultTerminator::~AssaultTerminator(void)
{
	std::cout << "I’ll be back ..." << std::endl;
	return;
}

AssaultTerminator &AssaultTerminator::operator=(AssaultTerminator const &r) 
{
	(void)r;
	return (*this);
}

ISpaceMarine	*AssaultTerminator::clone() const
{
	ISpaceMarine	*ret = new AssaultTerminator(*this);
	return (ret);
}

void			AssaultTerminator::battleCry() const
{
	std::cout << "This code is unclean. PURIFY IT !" << std::endl;
	return;
}

void			AssaultTerminator::rangedAttack() const
{
	std::cout << "* does nothing *" << std::endl;
	return;
}

void			AssaultTerminator::meleeAttack() const
{
	std::cout << "* attacks with chainfists *" << std::endl;
	return;
}
