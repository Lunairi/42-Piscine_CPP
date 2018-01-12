/* ************************************************************************** */
/*                                                                            */
/*    Cure.cpp               _             _              :::      ::::::::   */
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
#include "Cure.hpp"

Cure::Cure(std::string const &type) : _type(type), _xp(0)
{
	return;
}

Cure::Cure(Cure &obj)
{
	*this = obj;
	return;
}

Cure::~Cure(void)
{
	return;
}

Cure &Cure::operator=(Cure const &r) 
{
	this->_type = r._type;
	return (*this);
}

Cure*	Cure::clone(void) const
{
	Cure 	*cure = new Cure("Cure");

	return (cure);
}

void		Cure::use(ICharacter &target)
{
	this->increaseXP();
	std::cout << "* heals " << target.getName() << "'s wounds' *" << std::endl;
}