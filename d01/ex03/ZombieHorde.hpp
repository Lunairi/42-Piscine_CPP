/* ************************************************************************** */
/*                                                                            */
/*    ZombieHorde.hpp        _                            :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_H
# define ZOMBIEHORDE_H

#include <iostream>
#include <string>
#include "Zombie.hpp"

class	ZombieHorde {

	public: 

		ZombieHorde(int n); 
		~ZombieHorde(void);

		int		amount;
		Zombie	*horde;

		void 			announce();
		std::string		randomname(int x);

};

#endif