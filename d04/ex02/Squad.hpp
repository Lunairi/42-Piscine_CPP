/* ************************************************************************** */
/*                                                                            */
/*    Squad.hpp              _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef SQUAD_H
# define SQUAD_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

class	Squad : public ISquad
{

	typedef struct _marinelist
	{
		ISpaceMarine 			*marine;
		struct _marinelist		*next;
	}				t_marinelist;

	public:

		Squad(void);
		Squad(Squad &obj);
		virtual ~Squad(void);
		Squad &operator=(Squad const &r);

		int				getCount() const;
		ISpaceMarine*	getUnit(int) const;
		int				push(ISpaceMarine*);

	private:
		int					_unit;
		struct _marinelist	*_marine;
};

#endif