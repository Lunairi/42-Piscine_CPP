/* ************************************************************************** */
/*                                                                            */
/*    ImageDisplay.cpp       _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#include <Gkrellm.hpp>

void	image_display(std::vector<std::string> flags)
{
	std::vector<IMonitorModule*> 	modules;

	int		input[] = { 0, 0, 0, 0, 0, 0, 0, 0};

	if (flags.size() == 0)
	{
		modules.push_back(new HostNameModule(" HOST NAME "));
		modules.push_back(new OSInfoModule(" OS INFO "));
		modules.push_back(new DateTimeModule(" DATE & TIME "));
		modules.push_back(new CPUInfoModule(" CPU INFO "));
		modules.push_back(new CPUUsageModule(" CPU USAGE "));
		modules.push_back(new RAMUsageModule(" RAM USAGE "));
		modules.push_back(new NetworkInfoModule(" NETWORK INFO "));
		modules.push_back(new PonyModule(" MAGICAL PONY "));
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
			else if (flags.at(i) == "-p" && input[7] == 0)
			{
				input[7] = 1;
				modules.push_back(new PonyModule(" MAGICAL PONY "));
			}
			i++;
		}
	}

	int	size = modules.size() * 320 + 70;
	sf::RenderWindow	window(sf::VideoMode(600, size), "Kill me please");

	GraphicDisplay		graphicDisplay(modules, window);

	graphicDisplay.renderOutput();
	while(window.isOpen())
	{
		try
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			graphicDisplay.refreshOutput();
		}
		catch (const std::exception &e)
		{
			window.close();
			exit(1);
		}
	}
	(void)flags;

}