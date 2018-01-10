/* ************************************************************************** */
/*                                                                            */
/*    SuperTrap.hpp           _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef SUPERTRAP_H
# define SUPERTRAP_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class	SuperTrap : public FragTrap, public NinjaTrap
{

	public:

		SuperTrap(void);
		SuperTrap(std::string name);
		SuperTrap(SuperTrap &obj);
		virtual ~SuperTrap(void);
		SuperTrap &operator=(SuperTrap const &r);

}; 

#endif