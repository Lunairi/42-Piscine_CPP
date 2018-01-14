/* ************************************************************************** */
/*                                                                            */
/*    Timer.class.cpp        _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#include <Space.Invaders.hpp>

Timer::Timer(void) {}

Timer::Timer(clock_t t) : _timer(t) {}

Timer::Timer(Timer &obj) { 
	*this = obj;
}

Timer::~Timer(void) {}

Timer &Timer::operator=(Timer const &r) {
	this->_timer = r._timer;
	return (*this);
}

int		Timer::checkTime(clock_t t) {
	return ((this->_timer - t) / (CLOCKS_PER_SEC / 1000));
}

int		Timer::getSec(clock_t t) {
	return ((t - this->_timer) / CLOCKS_PER_SEC);
}
