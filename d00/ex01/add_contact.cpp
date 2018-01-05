/* ************************************************************************** */
/*                                                                            */
/*    add_contact.hpp          _             _            :::      ::::::::   */
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
#include "add_contact.hpp"

Info::Info(void) 
{
	return;
}

Info::~Info(void) 
{
	return;
}

void	Info::add_info(std::string input, int i) 
{
	if (i == 0)
		this->_firstname = input;
	else if (i == 1)
		this->_lastname = input;
	else if (i == 2)
		this->_nickname = input;
	else if (i == 3)
		this->_login = input;
	else if (i == 4)
		this->_address = input;
	else if (i == 5)
		this->_email = input;
	else if (i == 6)
		this->_phone = input;
	else if (i == 7)
		this->_birthday = input;
	else if (i == 8)
		this->_meal = input;
	else if (i == 9)
		this->_panties = input;
	else if (i == 10)
		this->_secret = input;
	else if (i == 11)
		this->_moment = input;
	else if (i == 12)
		this->_murder = input;
	else if (i == 13)
		this->_wtf = input;
	else if (i == 14)
		this->_tired = input;
	else if (i == 15)
		this->_traps = input;
	else if (i == 16)
		this->_last = input;
}

std::string	Info::get_info(int i) 
{
	if (i == 0)
		return (this->_firstname);
	else if (i == 1)
		return (this->_lastname);
	else if (i == 2)
		return (this->_nickname);
	else if (i == 3)
		return (this->_login);
	else if (i == 4)
		return (this->_address);
	else if (i == 5)
		return (this->_email);
	else if (i == 6)
		return (this->_phone);
	else if (i == 7)
		return (this->_birthday);
	else if (i == 8)
		return (this->_meal);
	else if (i == 9)
		return (this->_panties);
	else if (i == 10)
		return (this->_secret);
	else if (i == 11)
		return (this->_moment);
	else if (i == 12)
		return (this->_murder);
	else if (i == 13)
		return (this->_wtf);
	else if (i == 14)
		return (this->_tired);
	else if (i == 15)
		return (this->_traps);
	else if (i == 16)
		return (this->_last);
	return ("ERROR");
}