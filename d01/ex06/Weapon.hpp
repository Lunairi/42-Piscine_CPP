/* ************************************************************************** */
/*                                                                            */
/*    Weapon.hpp             _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>
#include <sstream>
#include <string>

class	Weapon {

	public: 

		Weapon(std::string input); 
		~Weapon(void);

		std::string 		typew;
		std::string const 	&getType();
		void				 setType(std::string input);

};

#endif