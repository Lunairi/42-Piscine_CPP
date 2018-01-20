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

int		main() {

	std::vector<IMonitorModule*> 	modules;
	int								c = 0;

	modules.push_back(new HostNameModule(" HOST NAME "));
	modules.push_back(new OSInfoModule(" OS INFO "));
	modules.push_back(new DateTimeModule(" DATE & TIME "));
	modules.push_back(new CPUInfoModule(" CPU INFO "));
	modules.push_back(new CPUUsageModule(" CPU USAGE "));
	modules.push_back(new RAMUsageModule(" RAM USAGE "));
	modules.push_back(new NetworkInfoModule(" NETWORK INFO "));

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

	return (0);
}





















