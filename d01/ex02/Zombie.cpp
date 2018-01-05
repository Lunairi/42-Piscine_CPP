/* ************************************************************************** */
/*                                                                            */
/*    Zombie.cpp             _             _              :::      ::::::::   */
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
#include "Zombie.hpp"

Zombie::Zombie(std::string nick, std::string desc) : name(nick), typez(desc)
{
	announce(this->name, this->typez);
	return;
}

Zombie::~Zombie(void) 
{
	std::cout << this->name << " has returned back to the underworld and disappeared." << std::endl;
	return;
}

void	Zombie::announce(std::string name, std::string type)
{
	std::cout << "<" << name << " (" << type << ")>  Braiiiiiiinnnssss.." << std::endl;
	return;
}

void	Zombie::death()
{
	std::cout << this->name << " has returned back to the underworld and disappeared." << std::endl;
}