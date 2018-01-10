/* ************************************************************************** */
/*                                                                            */
/*    FragTrap.hpp           _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{

	public:

		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap &obj);
		virtual ~FragTrap(void);
		FragTrap &operator=(FragTrap const &r);

		void	vaulthunter_dot_exe(std:: string const &target);
		void	meatUnicycle(std:: string const &target);
		void	tripleClocked(std:: string const &target);
		void	shhhhTrap(std:: string const &target);
		void	rubberDucky(std:: string const &target);
		void	senselessSacrifice(std:: string const &target);


}; 

#endif