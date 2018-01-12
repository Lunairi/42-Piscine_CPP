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


int				isOp(char c, int *p)
{
	if (c == '(' || c == ')')
	{
		*p = *p + 1;
		return (1);
	}
	else if (c == '+' || c == '-' || c == '*' || c == '/')
		return (1);
	return (0);
}

std::string		rpn(std::string str)
{
	// int i = 0;
	int num = 0;
	int p = 0;
	int oper = 0;
	float number = 0;
	std::ostringstream ret;
	std::string op = "";
	std::string::size_type size = 0;

	while(str[0] != '\0')
	{
		std::cout << "GOING THROUGH " << str[0] << std::endl;
		if (isOp(str[0], &p))
		{
			if (str[0] != '(' && str[0] != ')')
				op = op + str[0];
			oper++;
			str = str.substr(1, str.length());
			std::cout << "OP STR " << op << " OPER " << oper << std::endl;
			if (num == 2)
			{
				std::cout << "FUCK" << op[oper - 1] << std::endl;
				ret << op[oper - 1] << " ";
				op = op.substr(1, (op.length() - 1));
				oper--;
				num--;
			}
		}
		else if (str[0] != ' ')
		{
			number = std::stof(str, &size);
			ret << number << " ";
			str = str.substr(size, str.length());
			num++;
			std::cout << "RET STR " << ret << " num value " << num << std::endl;
		}
		else
			str = str.substr(1, str.length());
		size = 0;
	}
	std::string	retur(ret.str());
	return (retur);
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
	std::cout << "EQUATION " << equation << std::endl;
	delete ret;
	return (0);
}
