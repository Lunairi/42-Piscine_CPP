/* ************************************************************************** */
/*                                                                            */
/*    ScavTrap.hpp           _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>

class	ScavTrap
{

	public:

		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap &obj);
		virtual ~ScavTrap(void);
		ScavTrap &operator=(ScavTrap const &r);

		void	rangedAttack(std::string const &target);
		void	meleeAttack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	rename(std::string input);
		void	displayStats(void);

		void	challengeNewcomer(void);

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