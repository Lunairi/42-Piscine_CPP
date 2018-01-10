/* ************************************************************************** */
/*                                                                            */
/*    Enemy.hpp              _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>

class	Enemy
{

	public:

		Enemy(void);
		Enemy(int hp, std::string const &type);
		Enemy(Enemy &obj);
		virtual ~Enemy(void);
		Enemy &operator=(Enemy const &r);

		std::string		getType(void) const;
		int				getHP(void) const;
		void			setHP(int i);

		virtual void	takeDamage(int);

	private:
		int				_hp;
		std::string		_type;

};

#endif