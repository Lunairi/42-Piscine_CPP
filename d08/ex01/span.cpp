/* ************************************************************************** */
/*                                                                            */
/*    Span.cpp               _             _              :::      ::::::::   */
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
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include "span.hpp"

Span::Span(unsigned int n) : _size(n)
{
	_store.reserve(n);
	return;
}

Span::Span(Span &obj) 
{
	*this = obj;
	return;
}

Span::~Span(void)
{
	return;
}

Span &Span::operator=(Span const &r) 
{
	this->_store = r._store;
	return (*this);
}

void		Span::addNumber(int num)
{
	if (_store.size() < _size)
		_store.push_back(num);
	else
		throw Span::StorageLimitException();
}

int			Span::shortestSpan(void)
{
	std::vector<int>	min = _store;
	return(*std::min_element(min.begin(), min.end()));
}

int			Span::longestSpan(void)
{
	std::vector<int>	max = _store;
	return(*std::max_element(max.begin(), max.end()));
}


/*
** StorageLimitException Nested Class
*/

Span::StorageLimitException::StorageLimitException(void)
{
	return;
}

Span::StorageLimitException::StorageLimitException(StorageLimitException const &obj)
{
	*this = obj;
	return;
}

Span::StorageLimitException::~StorageLimitException(void) throw()
{
	return;
}

Span::StorageLimitException &Span::StorageLimitException::operator=(StorageLimitException const &r) 
{
	(void)r;
	return (*this);
}

const char* Span::StorageLimitException::what() const throw()
{
	return ("Error: Storage capacity is maxed.");
}