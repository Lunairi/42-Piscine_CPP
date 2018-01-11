/* ************************************************************************** */
/*                                                                            */
/*    AssaultTerminator.hpp  _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef ASSAULTTERMINATOR_H
# define ASSAULTTERMINATOR_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "AssaultTerminator.hpp"
#include "ISpaceMarine.hpp"

class	AssaultTerminator : public ISpaceMarine
{
	public:

		AssaultTerminator(void);
		AssaultTerminator(AssaultTerminator const &obj);
		virtual ~AssaultTerminator(void);
		AssaultTerminator &operator=(AssaultTerminator const &r);

		ISpaceMarine*	clone() const;
		void			battleCry() const;
		void			rangedAttack() const;
		void			meleeAttack() const;
};

#endif