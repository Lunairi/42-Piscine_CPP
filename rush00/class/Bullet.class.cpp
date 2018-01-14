/* ************************************************************************** */
/*                                                                            */
/*    Bullet.class.cpp       _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#include <Space.Invaders.hpp>

Bullet::Bullet(void) {}

Bullet::Bullet(int x, int y) : _x(x), _y(y), _life(0) {}

Bullet::Bullet(Bullet &obj) { 
	*this = obj;
}

Bullet::~Bullet(void) {}

Bullet &Bullet::operator=(Bullet const &r) {
	this->_x = r._x;
	this->_y = r._y;
	return (*this);
}

int			Bullet::getX(void) {
	return (this->_x);
}

int			Bullet::getY(void) {
	return (this->_y);
}

void		Bullet::moveDown(void) {
	this->_y++;
}

void		Bullet::moveUp(void) {
	this->_y--;
}

void		Bullet::shootEBullet(void) {
	attron(COLOR_PAIR(3));
	mvprintw(_y, _x, "v");
	attroff(COLOR_PAIR(3));
}

void		Bullet::eliteShot(void) {
	attron(COLOR_PAIR(5));
	mvprintw(_y, _x, "o");
	attroff(COLOR_PAIR(5));
}

void		Bullet::eliteDown(int i) {
	if (i % 3 == 0)
		this->_y++;
	else if (i % 3 == 1) {
		this->_y++;
		this->_x--;
	}
	else {
		this->_y++;
		this->_x++;
	}
}

void		Bullet::shootBullet(void) {
	attron(COLOR_PAIR(1));
	mvprintw(_y, _x, ".");
	attroff(COLOR_PAIR(1));
}

void		Bullet::clearBullet(void) {
	mvprintw(_y, _x, " ");
}

int			Bullet::checkLife(void) {
	return (this->_life);
}

void		Bullet::setLife(int i) {
	this->_life = i;
}

void		Bullet::setInfo(int x, int y, int life){
	this->_x = x;
	this->_y = y;
	this->_life = 1;
}


