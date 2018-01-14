/* ************************************************************************** */
/*                                                                            */
/*    Timer.class.hpp        _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef TIMER_H
# define TIMER_H

# include <Space.Invaders.hpp>

class	Timer {

	public:

		Timer(void);
		Timer(clock_t t);
		Timer(Timer &obj);
		virtual ~Timer(void);
		Timer &operator=(Timer const &r);

		int		checkTime(clock_t t);
		int		getSec(clock_t t);
		
	private:
		clock_t	_timer;
};

#endif
