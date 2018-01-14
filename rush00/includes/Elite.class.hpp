/* ************************************************************************** */
/*                                                                            */
/*    Elite.class.hpp        _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef ELITE_H
# define ELITE_H

# include <Space.Invaders.hpp>

class	Elite : public Enemy {

	public:

		Elite(void);
		Elite(int x, int y);
		Elite(Elite &obj);
		virtual ~Elite(void);
		Elite &operator=(Elite const &r);

		int		moveElite(int map, int end);
		void	clearElite(void);
		void	drawElite(void);
		int		isAlive(void);	
		int		isEHit(int x, int y);

};

#endif
