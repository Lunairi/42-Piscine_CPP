/* ************************************************************************** */
/*                                                                            */
/*    iter.cpp               _             _              :::      ::::::::   */
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
#include <iomanip>
#include <sstream>
#include "Array.hpp"

int				main(void)
{
	srand(time(0));
	int	n = rand() % 10;
	Array<int> test(n);

	std::cout << "Size of Array made: " << test.size() << std::endl << std::endl <<
		"Now filling array with random stuff and printing it" << std::endl;

	try
	{
		unsigned int i = 0;
		while (i < test.size())
		{
			test[i] = rand() % 100;
			i++;
		}
		i = 0;
		while (i <= test.size())
		{
			std::cout << "Array[" << i << "] Content: " << test[i] << std::endl;
			i++;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
