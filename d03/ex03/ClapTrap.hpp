/* ************************************************************************** */
/*                                                                            */
/*    ClapTrap.hpp           _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>

class	ClapTrap
{

	public:

		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap &obj);
		virtual ~ClapTrap(void);
		ClapTrap &operator=(ClapTrap const &r);

		void	rangedAttack(std::string const &target);
		void	meleeAttack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	rename(std::string input);
		void	displayStats(void);

		void	setStats(std::string name, int lvl, int hp, int mhp, int sp, int msp, int patk, int ratk, int armor);

		std::string			name;

		int		getHp(void);
		int		getMhp(void);
		int		getSp(void);
		int		getMsp(void);
		int		getLvl(void);
		int		getPatk(void);
		int		getRatk(void);
		int		getArmor(void);

		void	setHp(int i);
		void	setMhp(int i);
		void	setArmor(int i);
		void	setSp(int i);

	private:

		int					_hp;
		int					_mhp;
		int					_sp;
		int					_msp;
		int					_lvl;
		int					_patk;
		int					_ratk;
		int					_armor;

}; 

#endif