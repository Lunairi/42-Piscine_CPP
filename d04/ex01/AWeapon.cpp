/* ************************************************************************** */
/*                                                                            */
/*    AWeapon.cpp           _             _              :::      ::::::::   */
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
#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const &name, int apcost, int damage) : _name(name), _ap(apcost), _dmg(damage)
{
	return;
}

AWeapon::AWeapon(AWeapon &obj)
{
	*this = obj;
	return;
}

AWeapon::~AWeapon(void)
{
	return;
}

AWeapon &AWeapon::operator=(AWeapon const &r) 
{
	this->_name = r._name;
	this->_ap = r._ap;
	this->_dmg = r._dmg;
	return (*this);
}

std::string		AWeapon::getName() const
{
	return (this->_name);
}

int				AWeapon::getDamage() const
{
	return (this->_dmg);
}

int				AWeapon::getAPCost() const
{
	return (this->_ap);
}
