/* ************************************************************************** */
/*                                                                            */
/*    HumanB.hpp             _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

#include <iostream>
#include <sstream>
#include <string>
#include "Weapon.hpp"

class	HumanB {

	public: 

		HumanB(std::string nick); 
		~HumanB(void);

		Weapon 		*wep;
		std::string name;
		void	attack();
		void	setWeapon(Weapon &var);
};

#endif