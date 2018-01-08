/* ************************************************************************** */
/*                                                                            */
/*    main.cpp               _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

std::string	rpn(std::string str)
{
	int i = 1;
	int x = 0;
	int y = 0;
	float one;
	float two;
	std::string eq = str;
	std::string ret = "";
	std::string	sub = "";
	std::string first = "";
	std::string second = "";

	std::cout << "INSERTION HERE [" << eq << "]" << std::endl;
	std::size_t found = eq.find_last_of("(");
	if (found!=std::string::npos)
		x = found;
	found = eq.find(")");
	if (found!=std::string::npos)
		y = found;
	if (x != 0 && y != 0)
	{
		sub = eq.substr((x + 1), (y - x - 1));
		first = eq.substr(0, x);
		second = eq.substr(y + 1, (y - eq.length()));
		eq = first + second;
		std::cout << "OUTPUT " << sub << std::endl;
		std::cout << "NEW EQ \n" << first << "\n&\n" << second << "\nEQUAL\n" << eq << std::endl;
		rpn(sub);
	}
	else
	{
		std::string::size_type size;
		one = std::stof(eq, &size);
		// two = std::stof(eq.substr(size));
		std::cout << "NUM " << one <<  std::endl;
	}
	return (ret);

}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Please provide one arguement with a valid arithmetic equation you'd like to resolve." << std::endl;
		return (0);
	}
	Fixed *ret = new Fixed(0);
	std::string input = av[1];
	std::string equation = rpn(input);
	delete ret;
	return (0);
}
