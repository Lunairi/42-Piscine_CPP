/* ************************************************************************** */
/*                                                                            */
/*    TextDisplay.cpp        _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#include <Gkrellm.hpp>

void	text_display(std::vector<std::string> flags)
{
	(void)flags;
	std::vector<IMonitorModule*> 	modules;
	int								c = 0;

	int		input[] = { 0, 0, 0, 0, 0, 0, 0 };

	if (flags.size() == 0)
	{
		modules.push_back(new HostNameModule(" HOST NAME "));
		modules.push_back(new OSInfoModule(" OS INFO "));
		modules.push_back(new DateTimeModule(" DATE & TIME "));
		modules.push_back(new CPUInfoModule(" CPU INFO "));
		modules.push_back(new CPUUsageModule(" CPU USAGE "));
		modules.push_back(new RAMUsageModule(" RAM USAGE "));
		modules.push_back(new NetworkInfoModule(" NETWORK INFO "));
	}
	else
	{
		size_t i = 0;

		while (i < flags.size())
		{
			if (flags.at(i) == "-h" && input[0] == 0)
			{
				input[0] = 1;
				modules.push_back(new HostNameModule(" HOST NAME "));
			}
			else if (flags.at(i) == "-o" && input[1] == 0)
			{
				input[1] = 1;
				modules.push_back(new OSInfoModule(" OS INFO "));
			}
			else if (flags.at(i) == "-d" && input[2] == 0)
			{
				input[2] = 1;
				modules.push_back(new DateTimeModule(" DATE & TIME "));
			}
			else if (flags.at(i) == "-c" && input[3] == 0)
			{
				input[3] = 1;
				modules.push_back(new CPUInfoModule(" CPU INFO "));
			}
			else if (flags.at(i) == "-u" && input[4] == 0)
			{
				input[4] = 1;
				modules.push_back(new CPUUsageModule(" CPU USAGE "));
			}
			else if (flags.at(i) == "-r" && input[5] == 0)
			{
				input[5] = 1;
				modules.push_back(new RAMUsageModule(" RAM USAGE "));
			}
			else if (flags.at(i) == "-n" && input[6] == 0)
			{
				input[6] = 1;
				modules.push_back(new NetworkInfoModule(" NETWORK INFO "));
			}
			i++;
		}
	}


	TerminalDisplay		textDisplay(modules);

	textDisplay.renderOutput();
	while (1)
	{
		try
		{
			if ((c = getch()) != ERR)
			{
				endwin();
				exit(1);
			}
			textDisplay.refreshOutput();
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
			endwin();
			exit(1);
		}
	}
}