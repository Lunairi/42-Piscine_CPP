/* ************************************************************************** */
/*                                                                            */
/*    ZombieEvent.cpp        _             _              :::      ::::::::   */
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
#include <cstdlib>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(std::string nick, std::string desc)
{
	this->typez = desc;
	newZombie(nick);
	return;
}

ZombieEvent::~ZombieEvent(void) 
{
	std::cout << "All Zombie Events has returned back to the ground of the earth." << std::endl;
	return;
}

void	ZombieEvent::setZombieType(std::string desc)
{
	this->typez = desc;
	std::cout << "Zombie type has been set to: " << this->typez << std::endl;
	return;
}

Zombie*	ZombieEvent::newZombie(std::string name)
{
	Zombie	*createZombie = new Zombie(name, this->typez);
	return (createZombie);
}

Zombie*	ZombieEvent::randomChump()
{
	srand(time(0));
	int i = rand();
	std::string name = " ";

	if (i % 8 == 0)
		name = "Gracia";
	else if (i % 8 == 1)
		name = "Poppuri";
	else if (i % 8 == 2)
		name = "Sadie";
	else if (i % 8 == 3)
		name = "Fae";
	else if (i % 8 == 4)
		name = "Misteltainn";
	else if (i % 8 == 5)
		name = "Nocturna";
	else if (i % 8 == 6)
		name = "Lyra";
	else
		name = "Rhyme";
	Zombie	*createZombie = new Zombie(name, this->typez);

	return (createZombie);
}