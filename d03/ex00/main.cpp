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

int	main()
{
	FragTrap trapone;

	trapone.meleeAttack("Bandits");
	trapone.rangedAttack("Raiders");
	trapone.takeDamage(50);
	trapone.beRepaired(20);
	trapone.beRepaired(50);
	trapone.takeDamage(120);
	trapone.beRepaired(500);
	trapone.rename("4LL-MT");
	trapone.beRepaired(20);

	FragTrap traptwo(trapone);
	traptwo.rename("K1LL-B0T");
	traptwo.meleeAttack("4LL-MT");
	trapone.takeDamage(30);

	trapone.vaulthunter_dot_exe("Skags");
	traptwo.vaulthunter_dot_exe("Also Skags");
	trapone.vaulthunter_dot_exe("More Skags");
	traptwo.vaulthunter_dot_exe("Even More Skags");

	trapone.displayStats();
	traptwo.displayStats();
	
	return (0);
}