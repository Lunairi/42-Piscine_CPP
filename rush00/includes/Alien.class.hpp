/* ************************************************************************** */
/*                                                                            */
/*    Alien.class.hpp        _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef ALIEN_H
# define ALIEN_H

# include "Space.Invaders.hpp"

class	Alien : public Enemy {

	public:

		Alien(void);
		Alien(int x, int y);
		Alien(Alien &obj);
		virtual ~Alien(void);
		Alien &operator=(Alien const &r);

		int		movement(int map, int end);
		int		isAlive(void);

};

#endif
