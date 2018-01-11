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
#include "ISpaceMarine.hpp"
#include "ISquad.hpp"
#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

int main()
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;

	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc;

	std::cout << std::endl << std::endl << "Custom Testing, copying a marine" << std::endl << std::endl;

	AssaultTerminator	*Gracia = new AssaultTerminator;
	ISpaceMarine		*Poppuri = new AssaultTerminator(*Gracia);
	TacticalMarine		*Ally = new TacticalMarine;
	ISpaceMarine		*Bella = new TacticalMarine(*Ally);
	ISpaceMarine		*Lyra = new TacticalMarine;
	ISpaceMarine		*Heidi = new AssaultTerminator;
	ISquad				*Team = new Squad;
	
	std::cout << std::endl << std::endl << "Adding 2 Assault, 2 Tactical" << std::endl << std::endl;

	Team->push(Poppuri);
	Team->push(Bella);
	Team->push(Heidi);
	Team->push(Lyra);

	std::cout << std::endl << std::endl << "Copying everything over" << std::endl << std::endl;

	ISquad				*Opponent = Team;
	for (int i = 0; i < Opponent->getCount(); ++i)
	{
		ISpaceMarine* test = Opponent->getUnit(i);
		test->battleCry();
		test->rangedAttack();
		test->meleeAttack();
	}

	std::cout << std::endl << std::endl << "Deleting/freeing all heap usage" << std::endl << std::endl;

	delete Opponent;

	std::cout << std::endl << std::endl << "Deleting other stuff that isn't part of the Squad" << std::endl << std::endl;
	delete Gracia;
	return 0;
}