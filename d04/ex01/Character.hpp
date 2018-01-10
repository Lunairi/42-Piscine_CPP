/* ************************************************************************** */
/*                                                                            */
/*    Character.hpp          _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class	Character
{

	public:

		Character(void);
		Character(std::string const &name);
		Character(Character &obj);
		virtual ~Character(void);
		Character &operator=(Character const &r);

		void			recoverAP();
		void			equip(AWeapon*);
		void			attack(Enemy*);

		std::string		getName() const;
		int				getAP() const;
		AWeapon			*getWeapon() const;

	private:
		std::string		_name;
		AWeapon			*_weapon;
		int				_ap;

};

std::ostream				&operator<<(std::ostream &o, Character const &r);

#endif