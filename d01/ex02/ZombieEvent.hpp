/* ************************************************************************** */
/*                                                                            */
/*    ZombieEvent.hpp        _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef ZOMBIE_EVENT_H
# define ZOMBIE_EVENT_H

#include <iostream>
#include <string>
#include "Zombie.hpp"

class	ZombieEvent {

	public: 

		ZombieEvent(std::string nick, std::string desc); 
		~ZombieEvent(void);

		std::string		typez;

		void	setZombieType(std::string desc);
		Zombie	*newZombie(std::string name);
		Zombie	*randomChump();

};

#endif