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
#include <fstream>
#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int	main()
{
	FragTrap trapone;
	ScavTrap scavone;

	std::cout << std::endl;

	trapone.meleeAttack("Lots of Skags");
	scavone.meleeAttack("Baby Skags");

	trapone.rangedAttack("All those Skags");
	scavone.rangedAttack("Half-Alive Skags");

	trapone.takeDamage(30);
	scavone.takeDamage(30);

	trapone.beRepaired(10);
	scavone.beRepaired(10);

	trapone.displayStats();
	scavone.displayStats();

	trapone.vaulthunter_dot_exe("Skags");
	scavone.challengeNewcomer();
	
	return (0);
}