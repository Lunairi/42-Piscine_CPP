/* ************************************************************************** */
/*                                                                            */
/*    Alien.class.cpp     	 _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#include <Space.Invaders.hpp>

Alien::Alien(void) : Enemy() {}

Alien::Alien(int x, int y) : Enemy(x, y) {}

Alien::Alien(Alien &obj) { 
	*this = obj;
}

Alien::~Alien(void) {}

Alien &Alien::operator=(Alien const &r) {
	this->_x = r._x;
	this->_y = r._y;
	this->_life = r._life;
	return (*this);
}

int			Alien::movement(int map, int end) {
	float prob = 1.0 * rand() / RAND_MAX;

	if (prob < 0.47) {
		if (this->_x > 2)	moveLeft();
		else				moveRight();
	}
	else if (prob < 0.95) {
		if (this->_x < end)	moveRight();
		else				moveLeft();
	}
	else {
		if (this->_y < (map - 2))	moveDown();
		else { 
			this->_life = 0;
			mvprintw(this->_y, this->_x, " ");
			return (1);
		}
	}
	return (0);
}

int			Alien::isAlive(void) {
	return (this->_life);
}
