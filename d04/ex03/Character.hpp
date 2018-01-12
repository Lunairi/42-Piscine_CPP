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
#include "AMateria.hpp"
#include "ICharacter.hpp"

class	Character : public ICharacter
{

	public:

		Character(void);
		Character(std::string const &name);
		Character(Character &obj);
		~Character(void);
		Character &operator=(Character const &r);


		std::string const & getName() const;
		void 				equip(AMateria* obj);
		void 				unequip(int i);
		void 				use(int i, ICharacter& target);

	private:

		AMateria		*_mat[4];
		std::string	_name;

};

#endif