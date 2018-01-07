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
#include <cerrno>
#include <cstring>



int		main(int ac, char **av)
{
	std::string		input = "";
	std::string		line = "";
	std::string		file = "";
	int				i = 1;
	int				x = 0;
	int				y = 1;

	while (ac == 1)
	{
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			ac = -1;
			break;
		}
		std::cout << input << std::endl;
	}
	if (ac == -1)
		return (0);
	while (i < ac)
	{
		input = av[i];
		if (input.compare("-") == 0)
		{
			while(y)
			{
				std::getline(std::cin, input);
				if (std::cin.eof())
					y = 0;
				std::cout << input << std::endl;
			}
		}
		else
		{
			std::ifstream	ifs(input);
			if (ifs.is_open())
			{
				while (getline(ifs, line))
				{
					if (x != 0)
						file = file + '\n';
					file = file + line;
					x++;
				}
				x = 0;
				std::cout << file;
				file = "";
				line = "";
			}
			else
			{
				std::cout << "cat: " << input << ": " << strerror(errno) << std::endl;
			}
			ifs.close();
		}
		i++;
	}
	return (0);
}