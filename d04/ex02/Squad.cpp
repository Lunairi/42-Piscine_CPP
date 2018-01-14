/* ************************************************************************** */
/*                                                                            */
/*    Squad.cpp              _             _              :::      ::::::::   */
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
#include "Squad.hpp"

Squad::Squad(void) : _unit(0), _marine(NULL)
{
	return;
}

Squad::Squad(Squad &obj)
{
	this->_unit = obj._unit;

	t_marinelist *copy;
	t_marinelist *input;

	copy = this->_marine;
	input = obj._marine;

	while (input)
	{
		if (copy != NULL)
			copy = NULL;
		else
			copy = new t_marinelist;
		copy->marine = input->marine;
		copy->next = NULL;
		copy = copy->next;
		input = input->next;
	}
	this->_marine = copy;
	delete input;
	return;
}

Squad::~Squad(void)
{
	t_marinelist	*copy;

	while (this->_marine)
	{
		copy = this->_marine->next;
		delete this->_marine->marine;
		delete this->_marine;
		this->_marine = copy;
	}
	return;
}

Squad &Squad::operator=(Squad const &r) 
{
	this->_unit = r._unit;
	
	t_marinelist	*del;

	while (this->_marine)
	{
		del = this->_marine->next;
		delete this->_marine->marine;
		delete this->_marine;
		this->_marine = del;
	}
	delete del;

	t_marinelist *copy;
	t_marinelist *input;

	copy = this->_marine;
	input = r._marine;

	while (input)
	{
		if (copy != NULL)
			copy = NULL;
		else
			copy = new t_marinelist;
		copy->marine = input->marine;
		copy->next = NULL;
		copy = copy->next;
		input = input->next;
	}
	this->_marine = copy;
	delete input;

	return (*this);
}

int		Squad::getCount() const
{
	return (this->_unit);
}

int		Squad::push(ISpaceMarine *obj)
{
	t_marinelist	*copy;

	if (this->_marine == NULL)
	{
		this->_marine = new t_marinelist;
		this->_marine->marine = obj;
		this->_marine->next = NULL;
		this->_unit = this->_unit + 1;
		return (this->_unit);
	}
	copy = this->_marine;
	while (copy->next)
		copy = copy->next;
	copy->next = new t_marinelist;
	copy->next->marine = obj;
	copy->next->next = NULL;
	this->_unit = this->_unit + 1;
	return (this->_unit);
}

ISpaceMarine*		Squad::getUnit(int i) const
{
	t_marinelist	*ret;

	ret = this->_marine;
	while (i != 0 && ret != NULL)
	{
		ret = ret->next;
		i--;
	}
	return (ret->marine);
}