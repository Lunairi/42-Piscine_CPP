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
#include "Pony.hpp"

int		main()
{
	Pony	arta = Pony("Arta", 4, "Long Flowing", true);
	Pony	*lydeka = new Pony ("Lydeka", 2, "Serene", false);

	std::cout << std::endl;
	std::cout << "The Pony " << arta.name << " has " << arta.legs << " legs and " << arta.mane <<
		" that glistens in the beautiful sky. ";
	if (arta.saddle == true)
		std::cout << arta.name << " is trained and is willing to let you ride on the saddle she has.";
	else
		std::cout << arta.name << " is not trained and flies around aimlessly, yet gracefully.";

	std::cout << std::endl;
	std::cout << "The Pony " << lydeka->name << " has " << lydeka->legs << " legs and " << lydeka->mane <<
		" that glistens in the beautiful sky. ";
	if (lydeka->saddle == true)
		std::cout << lydeka->name << " is trained and is willing to let you ride on the saddle she has.";
	else
		std::cout << lydeka->name << " is not trained and flies around aimlessly, yet gracefully.";

	std::cout << std::endl << std::endl;
	delete lydeka;
	return (0);
}
