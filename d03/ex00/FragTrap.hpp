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

class	FragTrap
{

	public:

		FragTrap(void);
		FragTrap(FragTrap &obj);
		virtual ~FragTrap(void);

		void	rangedAttack(std::string const &target);
		void	meleeAttack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	rename(std::string input);
		void	displayStats();

		void	vaulthunter_dot_exe(std:: string const &target);
		void	meatUnicycle(std:: string const &target);
		void	tripleClocked(std:: string const &target);
		void	shhhhTrap(std:: string const &target);
		void	rubberDucky(std:: string const &target);
		void	senselessSacrifice(std:: string const &target);

		FragTrap &operator=(FragTrap const &r);

	private:

		int					_hp;
		int					_mhp;
		int					_sp;
		int					_msp;
		int					_lvl;
		std::string			_name;
		int					_patk;
		int					_ratk;
		int					_armor;

}; 

#endif