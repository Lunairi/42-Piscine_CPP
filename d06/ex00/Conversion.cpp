/* ************************************************************************** */
/*                                                                            */
/*    Conversion.cpp         _             _              :::      ::::::::   */
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
#include <exception>
#include "Conversion.hpp"

Conversion::Conversion(std::string input) : _input(input)
{
	return;
}

Conversion::Conversion(Conversion &obj) 
{
	*this = obj;
	return;
}

Conversion::~Conversion(void)
{
	return;
}

Conversion &Conversion::operator=(Conversion const &r) 
{
	this->_input = r._input;
	return (*this);
}

/*
** Conversion Catch Error And Cast
*/

Conversion::operator char(void) const
{
	int ret = 0;

	try
	{
		ret = std::stoi(this->_input);
	}
	catch (const std::exception &e)
	{
		throw (ConversionErrorException());
	}
	return (static_cast<char>(ret));
	
}

Conversion::operator int(void) const
{
	int ret = 0;
	try
	{
		ret = std::stoi(this->_input);
	}
	catch (const std::exception &e)
	{
		throw (ConversionErrorException());
	}
	return (ret);
	
}

Conversion::operator float(void) const
{
	float ret = 0.0;
	try
	{
		ret = std::stof(this->_input);
	}
	catch (const std::exception &e)
	{
		throw (ConversionErrorException());
	}
	return (ret);
	
}

Conversion::operator double(void) const
{
	float ret = 0.0;
	try
	{
		ret = std::stof(this->_input);
	}
	catch (const std::exception &e)
	{
		throw (ConversionErrorException());
	}
	return (ret);
	
}


/*
** ConversionErrorException Nested Class
*/

Conversion::ConversionErrorException::ConversionErrorException(void)
{
	return;
}

Conversion::ConversionErrorException::ConversionErrorException(ConversionErrorException const &obj)
{
	*this = obj;
	return;
}

Conversion::ConversionErrorException::~ConversionErrorException(void) throw()
{
	return;
}

Conversion::ConversionErrorException &Conversion::ConversionErrorException::operator=(ConversionErrorException const &r) 
{
	(void)r;
	return (*this);
}

const char* Conversion::ConversionErrorException::what() const throw()
{
	return ("impossible");
}