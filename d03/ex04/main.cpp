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
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

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

	FragTrap traptwo(trapone);
	ScavTrap scavtwo(scavone);

	traptwo.rename("I AM A TRAP");
	scavtwo.rename("I AM A SCAVENGER");

	NinjaTrap ninone("I AM A NINJA");
	ninone.ninjaShoeBox(traptwo);
	ninone.ninjaShoeBox(scavtwo);

	NinjaTrap nintwo;
	nintwo.ninjaShoeBox(ninone);

	ClapTrap clapone("I AM THE ORIGINAL");
	nintwo.ninjaShoeBox(clapone);

	SuperTrap superone;
	superone.meleeAttack("Millions of Skags");
	superone.rangedAttack("Good Clone of Handsome Jack");

	superone.rename("I AM THE SUPER");

	SuperTrap supertwo(superone);

	superone.vaulthunter_dot_exe("Skagzilla");
	superone.ninjaShoeBox(trapone);

	superone.displayStats();
	supertwo.displayStats();
	
	return (0);
}