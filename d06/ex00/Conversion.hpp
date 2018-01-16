/* ************************************************************************** */
/*                                                                            */
/*    Conversion.hpp         _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef CONVERSION_H
# define CONVERSION_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <exception>

class	Conversion
{

	public:

		Conversion(void);
		Conversion(std::string input);
		Conversion(Conversion &obj);
		virtual ~Conversion(void);
		Conversion &operator=(Conversion const &r);

		class ConversionErrorException : public std::exception
		{
			public:
				
				ConversionErrorException(void);
				ConversionErrorException(ConversionErrorException const &obj);
				virtual ~ConversionErrorException(void) throw();
				ConversionErrorException &operator=(ConversionErrorException const &r);
				virtual const char* what() const throw();
		};

		operator char(void) const;
		operator int(void) const;
		operator float(void) const;
		operator double(void) const;


	private:

		std::string _input;


}; 


#endif