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
#include "ZombieEvent.hpp"

int		main()
{
	std::cout << "Spawning a Zombie on Stack" << std::endl;
	Zombie	Arta = Zombie("Arta", "School Girl");

	std::cout << std::endl << "Spawning a Zombie Event on Heap" << std::endl;
	ZombieEvent	*Lydeka = new ZombieEvent("Lydeka", "Myrmidon");

	std::cout << std::endl << "Setting Zombie type to Popstar" << std::endl;
	Lydeka->setZombieType("Popstar");

	std::cout << std::endl << "Spawning Zombie Event again with new type" << std::endl;
	Lydeka->newZombie("Lydeka");

	std::cout << std::endl << "Changing zombie type to Assassin" << std::endl;
	Lydeka->setZombieType("Assassin");

	std::cout << std::endl << "Spawning random name Zombie Event with new type" << std::endl;
	Lydeka->randomChump();

	std::cout << std::endl << "Spawning another Zombie on Heap" << std::endl;
	Zombie *Rosa = new Zombie("Rosa", "Evangelica");

	std::cout << std::endl << "Eliminating all zombies." << std::endl;
	std::cout << std::endl << "In order of elimination: Rosa (Heap), Zombie Events (Heap), Arta (stack)" << std::endl << std::endl;
	delete Rosa;
	delete Lydeka;
	return (0);
}