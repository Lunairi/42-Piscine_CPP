/* ************************************************************************** */
/*                                                                            */
/*    Player.class.cpp       _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#include <Space.Invaders.hpp>

Player::Player(void) : Enemy() {}

Player::Player(int x, int y) : Enemy(x, y, 5) {}

Player::Player(Player &obj) { 
	*this = obj;
}

Player::~Player(void) {}

Player &Player::operator=(Player const &r) {
	this->_x = r._x;
	this->_y = r._y;
	this->_life = r._life;
	return (*this);
}

int			Player::loseLife(void) {
	this->_life--;
	if (this->_life <= 0)
		return (1);
	return (0);
}
int			Player::bulletHit(void) {
	static int i = 0;

	this->_life--;
	if (this->_life == 0 || (this->_life <= -1 && i >= 4))
	{
		i = 0;
		return (1);
	}
	if (this->_life <= -1)
	{
		this->_life = this->_life + 5 - i;
		i++;
	}
	return (0);
}