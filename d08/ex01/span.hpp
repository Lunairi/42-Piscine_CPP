/* ************************************************************************** */
/*                                                                            */
/*    Span.hpp               _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef Span_H
# define Span_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <exception>

class	Span
{

	public:

		Span(void);
		Span(unsigned int n);
		Span(Span &obj);
		virtual ~Span(void);
		Span &operator=(Span const &r);

		class StorageLimitException : public std::exception
		{
			public:
				
				StorageLimitException(void);
				StorageLimitException(StorageLimitException const &obj);
				virtual ~StorageLimitException(void) throw();
				StorageLimitException &operator=(StorageLimitException const &r);
				virtual const char* what() const throw();
		};

		void			addNumber(int num);
		int				shortestSpan(void);
		int				longestSpan(void);

	private:

		std::vector<int>	_store;

}; 


#endif