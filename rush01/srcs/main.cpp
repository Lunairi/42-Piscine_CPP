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

#include <Gkrellm.hpp>

int		input_error(void)
{
	std::cout << "You must enter a valid mode for ft_gkrellm" << std::endl <<
	"If you enter any modules they must be valid (no module specified will launch all modules)" << std::endl <<
	"Any defined modules will be defined in the order they're put" << std::endl <<
	"USAGE: 	ft_gkrellm [MODE] [MODULES]" << std::endl <<
	"-g 		enables graphic mode" << std::endl <<
	"-t 		enables text mode" << std::endl << std::endl <<
	"-h 		enables host module" << std::endl <<
	"-o 		enables os info module" << std::endl <<
	"-d 		enables date & time module" << std::endl <<
	"-c 		enables cpu info module" << std::endl <<
	"-u 		enables cpu usage module" << std::endl <<
	"-r 		enables ram usage module" << std::endl <<
	"-n 		enables network info module" << std::endl;

	return (0);
}

int		main(int ac, char **av)
{
	if (ac < 2)
		return (input_error());

	if (strcmp(av[1], "-t") && strcmp(av[1], "-g"))
		return (input_error());

	std::string	input[] = 
	{
		"-h", "-o", "-d", "-c", "-u", "-r", "-n"
	};

	std::vector<std::string>	flags;
	std::stringstream			v;
	int 						i = 1;
	int							x = -1;

	while (++i < ac)
	{
		while (++x < 7)
		{
			if (av[i] == input[x])
				flags.push_back(av[i]);
		}
		x = -1;
		try
		{
			v << flags.at(i - 2);
		}
		catch (const std::exception &e)
		{
			return (input_error());
		}
	}

	if (!strcmp(av[1], "-t"))
		text_display(flags);
	else
		image_display(flags);

	return (0);
}












