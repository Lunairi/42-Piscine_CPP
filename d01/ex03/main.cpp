/* ************************************************************************** */
/*                                                                            */
/*    main.cpp               _             _              :::      ::::::::   */
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
#include "ZombieHorde.hpp"

int		main(int ac, char **av)
{
	int n = 0;
	int i = 0;

	if (ac != 2)
	{
		std::cout << "Please enter one argument with how much zombies you want to spawn." << std::endl;
		return (0);
	}
	while (av[1][i] != '\0')
	{
		n = n * 10 + (av[1][i] - '0');
		i++;
	}
	std::cout << "You've entered " << n << " amounts of zombies to spawn. Spawnning will begin!" << std::endl << std::endl;
	ZombieHorde invasion = ZombieHorde(n);
	invasion.announce();

	std::cout << std::endl << "Time to say goodbye to the horde :(" << std::endl << std::endl;

	return (0);
}