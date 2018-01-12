/* ************************************************************************** */
/*                                                                            */
/*    Character.cpp          _             _              :::      ::::::::   */
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

Character::Character(std::string const &name) : _name(name)
{
	this->_mat[0] = NULL;
	this->_mat[1] = NULL;
	this->_mat[2] = NULL;
	this->_mat[3] = NULL;
	return;
}

Character::Character(Character &obj)
{
	this->_name = obj._name;
	this->_mat[0] = obj._mat[0];
	this->_mat[1] = obj._mat[0];
	this->_mat[2] = obj._mat[0];
	this->_mat[3] = obj._mat[0];
	return;
}

Character::~Character(void)
{
	int i = 0;

	while (i < 4)
	{
		if (this->_mat[i] != NULL)
			delete this->_mat[i]
		i++;
	}
	return;
}

Character &Character::operator=(Character const &r) 
{
	this->_name = r._name;
	this->_mat[0] = r._mat[0];
	this->_mat[1] = r._mat[0];
	this->_mat[2] = r._mat[0];
	this->_mat[3] = r._mat[0];
	return (*this);
}

std::string const & Character::getName() const
{
	return (_name);
}

void 				Character::equip(AMateria* obj)
{
	int	 i = 0;

	while (i < 4)
	{
		if (this->_mat[i] == NULL)
		{
			this->_mat[i] = obj;
			i = 5;
		}
		i++;
	}
	if (i == 4)
		std::cout << "You cannot equip anymore materias." << std::endl;
	return;
}

void 				Character::unequip(int i)
{
	if (this->_mat[i] == NULL)
		std::cout << "You have nothing equipped there." << std::endl;
	else
		this->_mat[i] = NULL;
	return;
}

void 				Character::use(int i, ICharacter& target)
{
	if (i >= 0 && i <= 3)
	{
		if (this->_mat[i] == NULL)
			std::cout << "There is no materia equipped here." << std::endl;
		else
			this->_mat[i]->use(target);
	}
	std::cout << "There is no materia equipped here." << std::endl;
}