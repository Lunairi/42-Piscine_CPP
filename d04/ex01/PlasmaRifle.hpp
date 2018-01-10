/* ************************************************************************** */
/*                                                                            */
/*    PlasmaRifle.hpp        _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef PLASMARIFLE_H
# define PLASMARIFLE_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "AWeapon.hpp"

class	PlasmaRifle : public AWeapon
{

	public:

		PlasmaRifle(void);
		PlasmaRifle(PlasmaRifle &obj);
		virtual ~PlasmaRifle(void);
		PlasmaRifle &operator=(PlasmaRifle const &r);

		void	attack(void);

};

#endif