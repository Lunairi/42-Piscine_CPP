/* ************************************************************************** */
/*                                                                            */
/*    Huamn.cpp              _             _              :::      ::::::::   */
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
#include "Human.hpp"

void Human::meleeAttack(std::string const & target)
{
	srand(time(0));
	int i = rand();

	if ((i % 4 == 0))
		std::cout << "You use your mythical japanese blade Kusanagi to strike down " << target << std::endl;
	else if ((i % 4 == 1))
		std::cout << "You use the legendary Durendal of Charlemagne to strike down " << target << std::endl;
	else if ((i % 4 == 2))
		std::cout << "You use the norse mythological Claíomh Solais to strike down " << target << std::endl;
	else
		std::cout << "You use the legendary Excalibur of King Author to strike down " << target << std::endl;
}

void Human::rangedAttack(std::string const & target)
{
	srand(time(0));
	int i = rand();

	if ((i % 4 == 0))
		std::cout << "You use the legenday Gandiva of Brahma & Arjuna to shoot down " << target << std::endl;
	else if ((i % 4 == 1))
		std::cout << "You use the legendary Sharanga of Vishnu to shoot down " << target << std::endl;
	else if ((i % 4 == 2))
		std::cout << "You use the norse mythological Ichaival of Odin to shoot down " << target << std::endl;
	else
		std::cout << "You use the mythical korean bow Gakgung to shoot down " << target << std::endl;
}

void Human::intimidatingShout(std::string const & target)
{
	srand(time(0));
	int i = rand();

	if ((i % 4 == 0))
		std::cout << "You shout 'FUS RO DAH!!!' at " << target << std::endl;
	else if ((i % 4 == 1))
		std::cout << "You begin shout singing 'Rick Astley Never Gonna Give You Up' at " << target << std::endl;
	else if ((i % 4 == 2))
		std::cout << "You begin shouting and beatboxing sick beats at " << target << std::endl;
	else
		std::cout << "You begin shouting and rapping 'Eminem RapGod' five times in a row without breathing at " << target << std::endl;
}

void Human::action(std::string const & action_name, std::string const & target)
{
	int i = 0;

	void (Human::*ptr[])(std::string const &) =
	{
		&Human::meleeAttack,
		&Human::rangedAttack,
		&Human::intimidatingShout 
	};

	std::string commands[] =
	{
		"meleeAttack",
		"rangedAttack",
		"intimidatingShout"
	};

	while (i < 3)
	{
		if (commands[i] == action_name)
		{
			(this->*ptr[i])(target);
			i = 4;
		}
		i++;
	}
	return;
}