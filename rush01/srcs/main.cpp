/* ************************************************************************** */
/*                                                                            */
/*    main.cpp.              _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#include <Gkrellm.hpp>

int		main(int ac, char **av)
{
	if (ac != 2 || (strcmp(av[1], "-t") && strcmp(av[1], "-g")))
	{
		std::cout << "You must enter a mode for ft_gkrellm" << std::endl <<
			"USAGE: ft_gkrellm [OPTION]" << std::endl <<
			"-g			enables graphic mode" << std::endl <<
			"-t			enables text mode" << std::endl;
		return (0);
	}
	
	if (!strcmp(av[1], "-t"))
		text_display();
	return (0);
}





















