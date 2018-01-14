/* ************************************************************************** */
/*                                                                            */
/*    Player.class.hpp       _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include <Space.Invaders.hpp>

class	Player : public Enemy {

	public:

		Player(void);
		Player(int x, int y);
		Player(Player &obj);
		virtual ~Player(void);
		Player &operator=(Player const &r);

		int		loseLife(void);

		int		bulletHit(void);

};

#endif
