/* ************************************************************************** */
/*                                                                            */
/*    Weapon.cpp             _             _              :::      ::::::::   */
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
#include "Weapon.hpp"

Weapon::Weapon(std::string input) : typew(input)
{
	return;
}

Weapon::~Weapon(void) 
{
	return;
}

std::string const &Weapon::getType()
{
	return (this->typew);
}

void		Weapon::setType(std::string input)
{
	this->typew = input;
	return;
}