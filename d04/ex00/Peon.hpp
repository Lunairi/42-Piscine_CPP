/* ************************************************************************** */
/*                                                                            */
/*    Peon.hpp               _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef PEON_H
# define PEON_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "Victim.hpp"

class	Peon : public Victim
{

	public:

		Peon(void);
		Peon(std::string name);
		Peon(Peon &obj);
		virtual ~Peon(void);
		Peon &operator=(Peon const &r);

		void	getPolymorphed(void) const;

		std::string		getName(void) const;

};

std::ostream	&operator<<(std::ostream &o, Peon const &r); 

#endif