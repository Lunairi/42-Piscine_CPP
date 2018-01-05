/* ************************************************************************** */
/*                                                                            */
/*    ZombieHorde.cpp        _                            :::      ::::::::   */
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
#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n) : amount(n)
{
	this->horde = new Zombie[n];
	int i = 0;

	while (i < this->amount)
	{
		this->horde[i].name = randomname(i);
		this->horde[i].typez = "Mindless Horde";
		i++;
	}
	return;
}

ZombieHorde::~ZombieHorde(void) 
{
	delete [] this->horde;
	return;
}

void ZombieHorde::announce(void)
{
	int i = 0;
	while (i < this->amount)
	{
		this->horde[i].announce();
		i++;
	}
}


std::string		ZombieHorde::randomname(int x)
{
	srand(time(0));
	int i = rand() + x;
	std::string name = " ";

	if (i % 26 == 0)
		name = "Gracia";
	else if (i % 26 == 1)
		name = "Poppuri";
	else if (i % 26 == 2)
		name = "Sadie";
	else if (i % 26 == 3)
		name = "Fae";
	else if (i % 26 == 4)
		name = "Misteltainn";
	else if (i % 26 == 5)
		name = "Nocturna";
	else if (i % 26 == 6)
		name = "Lyra";
	else if (i % 26 == 7)
		name = "Rhyme";
	else if (i % 26 == 8)
		name = "Aliza";
	else if (i % 26 == 9)
		name = "Bella";
	else if (i % 26 == 10)
		name = "Caprice";
	else if (i % 26 == 11)
		name = "Diana";
	else if (i % 26 == 12)
		name = "Englantine";
	else if (i % 26 == 13)
		name = "Heidi";
	else if (i % 26 == 14)
		name = "Io";
	else if (i % 26 == 15)
		name = "Jannette";
	else if (i % 26 == 16)
		name = "Olivia";
	else if (i % 26 == 17)
		name = "Querida";
	else if (i % 26 == 18)
		name = "Risa";
	else if (i % 26 == 19)
		name = "Taelys";
	else if (i % 26 == 20)
		name = "Ulia";
	else if (i % 26 == 21)
		name = "Vinnie";
	else if (i % 26 == 22)
		name = "Whitney";
	else if (i % 26 == 23)
		name = "Xalah";
	else if (i % 26 == 24)
		name = "Yuria";
	else
		name = "Zana";
	return (name);
}
