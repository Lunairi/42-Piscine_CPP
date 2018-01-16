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
#include <fstream>
#include <string>
#include "Conversion.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "You must enter one value to convert." << std::endl;
		return (0);
	}
	Conversion test(av[1]);
	std::cout << std::fixed << std::setprecision(1);

	std::cout << "char: ";
	try
	{
		int check = static_cast<int>(test);

		if (check >= 33 && check <= 126)
			std::cout << "'" << static_cast<char>(check) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	catch (Conversion::ConversionErrorException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "WTF?" << std::endl;
	}

	std::cout << "int: ";
	try
	{
		std::cout << static_cast<int>(test) << std::endl;
	}
	catch (Conversion::ConversionErrorException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "WTF?" << std::endl;
	}

	std::cout << "float: ";
	try
	{
		std::cout << static_cast<float>(test) << "f" << std::endl;
	}
	catch (Conversion::ConversionErrorException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "WTF?" << std::endl;
	}

	std::cout << "double: ";
	try
	{
		std::cout << static_cast<double>(test) << std::endl;
	}
	catch (Conversion::ConversionErrorException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "WTF?" << std::endl;
	}

	return (0);
}