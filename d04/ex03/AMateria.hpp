/* ************************************************************************** */
/*                                                                            */
/*    AMateria.hpp            _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "ICharacter.hpp"

class ICharacter;

class	AMateria
{

	public:

		AMateria(void);
		AMateria(std::string const &type);
		AMateria(AMateria &obj);
		virtual ~AMateria(void);
		AMateria &operator=(AMateria const &r);

		std::string const		&getType(void) const; //Returns the materia type
		unsigned int			getXP(void) const; //Returns the Materia s XP

		void					setType(std::string name);
		void					setXP(unsigned int xp);

		void					increaseXP(void);

		virtual AMateria*		clone(void) const = 0;
		virtual void			use(ICharacter& target);

	protected:

		std::string		_type;
		unsigned int	_xp;

};

#endif