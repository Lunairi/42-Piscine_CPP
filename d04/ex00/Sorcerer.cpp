/* ************************************************************************** */
/*                                                                            */
/*    Sorcerer.cpp           _             _              :::      ::::::::   */
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
#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title)
{
	std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
	return;
}

Sorcerer::Sorcerer(Sorcerer &obj)
{
	*this = obj;
	std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
	return;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same !" << std::endl;
	return;
}

Sorcerer &Sorcerer::operator=(Sorcerer const &r) 
{
	this->_name = r._name;
	this->_title = r._title;
	return (*this);
}

std::string		Sorcerer::getName() const
{
	return (this->_name);
}

std::string		Sorcerer::getTitle() const
{
	return (this->_title);
}

std::ostream	&operator<<(std::ostream &o, Sorcerer const &r)
{
	o << "I am " << r.getName() << ", " << r.getTitle() << ", and I like ponies !" << std::endl;
	return (o);
}

void	Sorcerer::polymorph(Victim const &ppl) const
{
	ppl.getPolymorphed();
	return;
}