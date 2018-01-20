/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_mode.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 20:27:08 by lwang             #+#    #+#             */
/*   Updated: 2018/01/14 01:07:22 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Gkrellm.hpp>

void	text_display()
{

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
}