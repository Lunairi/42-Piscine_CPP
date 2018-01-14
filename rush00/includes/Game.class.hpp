/* ************************************************************************** */
/*                                                                            */
/*    Game.class.hpp         _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef Game_H
# define Game_H

# include <Space.Invaders.hpp>

class	Game {

	public:

		Game(void);
		Game(int x, int y);
		Game(Game &obj);
		virtual ~Game(void);
		Game &operator=(Game const &r);

		int		checkEndgame(void);
		void	getInput(int c);

		void	spawnEnemy(void);
		void	moveEnemies(void);
		void	clearMove(void);

		void	spawnPlayer(void);
		void	movePlayer(void);

		void	playerBullet(void);
		void	moveBullets(void);

		void	moveEnemyBullets(void);
		void	enemyBullet(void);

		int		getScore(void);
		int		getLife(void);
		int		getLevel(void);

		void	drawPlayer(void);
		void	drawEnemy(void);

		int		getMenu(void);
		void	menuInput(int c);
		void	moveMenu(int i);

		void	setEndgame(int i);

		int		bulletCount(void);
		int		maxBulletCount(void);

	private:

		int		_checkHit(int x, int y);
		int		_checkPHit(int x, int y);

		int		_death;
		int		_input;
		Alien 	*_enemy;
		Elite	*_elite;
		Player	_player;
		int		_endgame;

		Bullet	*_bullet;
		Bullet	*_ebullet;
		Bullet	*_elitebullet;

		int		_mapx;
		int		_mapy;

		int		_score;
		int		_level;
		int		_ammoPouch;

		int		_bspd;

		int		_menu;

		int		_eElite;
		int		_eBoss;
		int		_eCount;
		int		_eBullet;

};

#endif
