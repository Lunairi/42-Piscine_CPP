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
#include <iomanip>
#include <sstream>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include "easyfind.hpp"

int				main(int ac, char **av)
{
	srand(time(0));

	if (ac != 2)
	{
		std::cout << "Please enter one value between 0 and 9 to be searched in the list." << std::endl;
		return (0);
	}

	std::list<int> list;

	list.push_back(rand() % 10);
	list.push_back(rand() % 10);
	list.push_back(rand() % 10);
	list.push_back(rand() % 10);
	list.push_back(rand() % 10);
	list.push_back(rand() % 10);
	list.push_back(rand() % 10);

	int search = atoi(av[1]);

	try
	{
		int ret = easyfind(list, search);
		std::cout << "Found value [" << search << "] at index: [" << ret << "]" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Value not found" << std::endl;
	}

	return 0;
}
