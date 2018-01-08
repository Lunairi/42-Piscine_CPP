/* ************************************************************************** */
/*                                                                            */
/*    Fixed.hpp              _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cmath>

class	Fixed 
{

	public:

		Fixed(void);
		Fixed(Fixed const &input);
		Fixed(int const input);
		Fixed(float const input);
		~Fixed(void);

		int			getRawBits(void) const;
		void		setRawBits(int const raw);

		float		toFloat(void) const;
		int			toInt(void) const;

		Fixed 		&operator=(Fixed const &r);

		bool		operator>(Fixed const &r);
		bool		operator<(Fixed const &r);
		bool		operator>=(Fixed const &r);
		bool		operator<=(Fixed const &r);
		bool		operator==(Fixed const &r);
		bool		operator!=(Fixed const &r);

		Fixed 		operator+(Fixed const &r);
		Fixed 		operator-(Fixed const &r);
		Fixed 		operator*(Fixed const &r);
		Fixed 		operator/(Fixed const &r);

		Fixed 		&operator++(void);
		Fixed		operator++(int input);
		Fixed 		&operator--(void);
		Fixed		operator--(int input);

		static Fixed		&min(Fixed 	 	 &l, Fixed 		 &r);
		static Fixed		&max(Fixed 	 	 &l, Fixed 		 &r);
		static Fixed const	&min(Fixed const &l, Fixed const &r);
		static Fixed const	&max(Fixed const &l, Fixed const &r);

	private:

		int					_value;
		static	int	const	_num;


}; 

std::ostream	&operator<<(std::ostream &o, Fixed const &r);

#endif