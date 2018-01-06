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

int		replace_word(std::string *input, std::string s1, std::string s2, int *i)
{
	std::size_t findword = input->find(s1);

	if (findword != std::string::npos)
	{
		input->replace(findword, s1.length(), s2);
		*i = *i + 1;
		return (1);
	}
	return (0);
}

void	parse_input(std::string file, std::string s1, std::string s2)
{
	std::ifstream	ifs(file);
	std::string		output = file + ".replace";
	std::string		input = "";
	std::string		line = "";
	int				i = 0;

	if (ifs.is_open())
	{
		std::ofstream	ofs(output);
		while (getline(ifs, line))
			input = input + line;
		while (replace_word(&input, s1, s2, &i));
		ofs << input << std::endl;
		std::cout << "You've replaced the word [" << s1 << "] with [" << s2 << "] " <<
					i << " many times." << std::endl <<
					"Here is what should be stored in " <<
					output << ":" << std::endl <<
					std::endl << input << std::endl << std::endl <<
					"Check it out yourself with system command:" << std::endl <<
					"cat " << output << std::endl;
		ofs.close();
	}
	else
	{
		std::cout << "Error: File does not exist. Please enter valid file." << std::endl;
		return;
	}
}

int 	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "How to use replace:" << std::endl <<
			"./replace [FILENAME] [STRING_ONE] [STRING_TWO]" << std::endl;
		return (0);
	}
	parse_input(av[1], av[2], av[3]);

}
