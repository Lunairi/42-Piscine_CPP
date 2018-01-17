/* ************************************************************************** */
/*                                                                            */
/*    Array.hpp              _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <exception>

template <typename T>
class Array
{
	public:
		Array<T>(void) : _array(NULL), _n(0)
		{
			return;
		}

		Array<T>(unsigned int n)
		{
			_n = n;
			_array = new T[n];
			return;
		}

		Array<T>(Array const &r)
		{
			*this = r;
			return;
		}

		Array<T> &operator=(Array const &r)
		{
			int i = -1;

			this->_n = r._n;
			delete this->_array;
			this->_array = new T[this->_n];

			while (++i < this->_n)
				this->_array[i] = r._array[i];
		}

		~Array<T>(void)
		{
			return;
		}


		T	&operator[](unsigned int n)
		{
			if (n >= this->_n)
				throw std::exception();
			return (this->_array[n]);
		}

		unsigned int size() const
		{
			return (this->_n);
		}


	private:
		T*				_array;
		unsigned int	_n;

};

#endif