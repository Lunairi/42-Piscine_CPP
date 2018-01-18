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
#include <random>
#include "span.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Please enter a positive value greater than 0" << std::endl;
		return (0);
	}

	unsigned int i = atoi(av[1]);
	srand(time(0));

	if (i <= 0)
	{
		std::cout << "Please enter a positive value greater than 0" << std::endl;
		return (0);
	}

	Span test(i);
	unsigned int x = 0;
	int y = 0;

	std::cout << "Generated an storage vector size of " << i << std::endl <<
		"Now filling vector with values:" << std::endl;
	while (x < i)
	{
		y = rand() % 10000;
		test.addNumber(y);
		std::cout << "[" << y << "] ";
		if (x % 13 == 0)
			std::cout << std::endl;
		x++;
	}

	std::cout << std::endl << std::endl << "Total Iterations: " << x;

	std::cout << std::endl << std::endl << "Smallest value in storage: " << test.shortestSpan() << std::endl <<
		"Largest value in storage: " << test.longestSpan() << std::endl << std::endl <<
		"Now adding one more to show error handling" << std::endl;

	try
	{
		test.addNumber(rand() % 10000);
	}
	catch (Span::StorageLimitException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << "WTF?" << std::endl;
	}

	return (0);
}