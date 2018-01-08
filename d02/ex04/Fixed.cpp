/* ************************************************************************** */
/*                                                                            */
/*    Fixed.cpp              _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
	return;
}

Fixed::Fixed(Fixed const &input)
{
	*this = input;
	return;
}

Fixed::Fixed(int const input)
{
	setRawBits(input << this->_num);
	return;
}

Fixed::Fixed(float const input)
{
	setRawBits(roundf(input * (1 << this->_num)));
	return;
}

Fixed::~Fixed(void)
{
	return;
}

/*
** Below are _value manipulation
*/

int		Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
	return;
}

int		Fixed::toInt(void) const
{
	return (getRawBits() >> this->_num);
}

float	Fixed::toFloat(void) const
{
	return ((float)getRawBits() / (1 << this->_num));
}

/*
** Below are bool expression operations
*/

bool	Fixed::operator>(Fixed const &r)
{
	return (this->toFloat() > r.toFloat());
}

bool	Fixed::operator<(Fixed const &r)
{
    return (this->toFloat() < r.toFloat());
}

bool	Fixed::operator>=(Fixed const &r)
{
    return (this->toFloat() >= r.toFloat());
}

bool	Fixed::operator<=(Fixed const &r)
{
    return (this->toFloat() <= r.toFloat());
}

bool	Fixed::operator==(Fixed const &r)
{
    return (this->toFloat() == r.toFloat());
}

bool	Fixed::operator!=(Fixed const &r)
{
    return (this->toFloat() != r.toFloat());
}

/*
** Below are basic math arithmetic operations
*/

Fixed	&Fixed::operator=(Fixed const &r)
{
	if (this != &r)
		this->_value = r.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(Fixed const &r)
{
	return (Fixed(this->_value + r.getRawBits()));
}

Fixed	Fixed::operator-(Fixed const &r)
{
	return (Fixed(this->_value - r.getRawBits()));
}

Fixed	Fixed::operator*(Fixed const &r)
{
	return (Fixed(this->toFloat() * r.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &r)
{
	if (r.toFloat() != 0)
		return (Fixed(this->toFloat() / r.toFloat()));
	else
	{
		std::cout << "Cannot divide by 0, resolving results to 0." << std::endl;
		return (Fixed(0));
	}
}

Fixed	&Fixed::operator++(void)
{
	this->_value = this->_value + 1;
	return (*this);
}

Fixed	Fixed::operator++(int input)
{
	Fixed fplus(*this);
	(void)input;

	this->_value = this->_value + 1;
	return (fplus);
}

Fixed	&Fixed::operator--(void)
{
	this->_value = this->_value - 1;
	return (*this);
}

Fixed	Fixed::operator--(int input)
{
	Fixed fminus(*this);
	(void)input;
	
	this->_value = this->_value - 1;
	return (fminus);
}

/*
** Below are min/max operations
*/

Fixed	&Fixed::min(Fixed &l, Fixed &r)
{
	return ((l.toFloat() < r.toFloat()) ? l : r);
}

Fixed 	&Fixed::max(Fixed &l, Fixed &r)
{
	return ((l.toFloat() > r.toFloat()) ? l : r);
}

Fixed const		&Fixed::min(Fixed const &l, Fixed const &r)
{
	return ((l.toFloat() < r.toFloat()) ? l : r);
}

Fixed const		&Fixed::max(Fixed const &l, Fixed const &r)
{
	return ((l.toFloat() > r.toFloat()) ? l : r);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &r)
{
	o << r.toFloat();
	return (o);
}

int	const	Fixed::_num = 8;
