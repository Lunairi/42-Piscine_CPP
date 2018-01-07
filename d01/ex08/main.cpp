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
#include "Human.hpp"

int	main(int ac, char **av)
{
	Human 		attack;
	std::string wep;
	std::string	target;

	if (ac != 3)
	{
		std::cout << "You must provide an attack and your target." << std::endl <<
			"Valid attacks (case sensitive): meleeAttack, rangedAttack, intimidatingShoot" << std::endl << std::endl <<
			"Usage: ./a.out [Valid Attack] [Your Target/Victim]" << std::endl;
		return (0);
	}
	wep = av[1];
	target = av[2];
	if ((wep.compare("meleeAttack") == 0) || (wep.compare("rangeAttack") == 0)
		|| (wep.compare("intimidatingShout") == 0))
	{
		if (target.compare("") == 0)
			target = "absolutely nothing";

		std::cout << "This is your input and attack!" << std::endl;
		attack.action(wep, target);
		std::cout << std::endl;

		std::cout << "Here are some automated attacks!" << std::endl << std::endl;

		std::cout << "Calling a melee attack!" << std::endl;
		attack.action("meleeAttack", "the woman who stole your man.");
		std::cout << std::endl;

		std::cout << "Calling a range attack!" << std::endl;
		attack.action("rangedAttack", "the man who stole your girl.");
		std::cout << std::endl;

		std::cout << "Shouting as an attack!" << std::endl;
		attack.action("intimidatingShout", "the kid who called you ugly.");
	}
	else
	{
		std::cout << "You must provide a valid attack." << std::endl <<
		"Valid attacks (case sensitive): meleeAttack, rangedAttack, intimidatingShoot" << std::endl << std::endl <<
		"Usage: ./a.out [Valid Attack] [Your Target/Victim]" << std::endl;
		return (0);
	}
}