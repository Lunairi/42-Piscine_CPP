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

void	fill_space(int *x, int *y, char *str, int col)
{
	while (*y < col)
	{
		mvprintw(*x, *y, str);
		*y = *y + 1;
	}
	*x = *x + 1;
	*y = -1;
}

int		main() {
	// srand(time(NULL));

	initscr();//creates std screen
	cbreak();//enter raw modal
	noecho();
	curs_set(0);

	int		col = 0;
	int		row = 0;
	int		x = 1;
	int		y = -1;
	int		length = 0;
	int		text = 0;

	getmaxyx(stdscr, row, col);

	/*
	** Hostname & Title of Project
	*/
	HostNameModule host(" HOSTNAME ");

	fill_space(&x, &y, (char*)"=", col);
	fill_space(&x, &y, (char*)"-", col);
	fill_space(&x, &y, (char*)"-", col);

	text = (col / 2) - 6;
	mvprintw((x - 1), text, " FT_GKRELLM ");
	fill_space(&x, &y, (char*)"-", col);

	length = host.getOutput().at(1).length();
	text = (col / 2) - (length / 2);
	mvprintw((x - 1), text, host.getOutput().at(1).c_str());

	fill_space(&x, &y, (char*)"-", col);
	fill_space(&x, &y, (char*)"=", col);
	fill_space(&x, &y, (char*)"-", col);

	length = host.getName().length();
	text = (col / 2) - (length / 2);
	mvprintw((x - 1), text, host.getName().c_str());

	fill_space(&x, &y, (char*)"-", col);
	fill_space(&x, &y, (char*)"-", col);

	length = host.getOutput().at(0).length();
	text = (col / 2) - (length / 2);
	mvprintw((x - 1), text, host.getOutput().at(0).c_str());
	fill_space(&x, &y, (char*)"=", col);
	fill_space(&x, &y, (char*)"-", col);

	/*
	** OS Info
	*/
	OSInfoModule oinfo(" OS INFO ");

	length = host.getName().length();
	text = (col / 2) - (length / 2);
	mvprintw((x - 1), text, oinfo.getName().c_str());
	fill_space(&x, &y, (char*)"-", col);
	fill_space(&x, &y, (char*)"-", col);

	length = oinfo.getOutput().at(0).length();
	text = (col / 2) - (length / 2);
	mvprintw((x - 1), text, oinfo.getOutput().at(0).c_str());
	fill_space(&x, &y, (char*)"-", col);

	length = oinfo.getOutput().at(1).length();
	text = (col / 2) - (length / 2);
	mvprintw((x - 1), text, oinfo.getOutput().at(1).c_str());
	fill_space(&x, &y, (char*)"=", col);


	box(stdscr, 0, 0);
	refresh();


	// /*
	// ** Date/time
	// */
	// std::string	month[] = 
	// {
	// 	"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug",
	// 	"Sep", "Oct", "Nov", "Dec"
	// };

	// std::string	week[] =
	// {
	// 	"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
	// };
	// time_t  timev = time(&timev);
	// struct tm *stamp = localtime(&timev);
	// std::cout << std::endl << "DATE" << std::endl <<
	// 	week[stamp->tm_wday] << " " <<
	// 	month[stamp->tm_mon] << " " << 
	// 	stamp->tm_mday << ", " << 
	// 	(1900 + stamp->tm_year) << std::endl << std::endl;
	// std::cout << "TIME" << std::endl;
	// std::cout << stamp->tm_hour << "-";
	// if (stamp->tm_min > 9)
	// 	std::cout << stamp->tm_min << "-";
	// else
	// 	std::cout << "0" << stamp->tm_min << "-";
	// if (stamp->tm_sec > 9)
	// 	std::cout << stamp->tm_sec << std::endl << std::endl;	
	// else
	// 	std::cout << "0" << stamp->tm_sec << std::endl << std::endl;
	// 	//Note to self: This needs to be automated, the time system

	// /*
	// ** CPU
	// */
	// char buffer[128];
	// size_t bufferlen = 128;
	// sysctlbyname("machdep.cpu.brand_string",&buffer,&bufferlen,NULL,0);
	// std::cout << "CPU INFO" << std::endl << buffer << std::endl << std::endl;

	// std::system( "/usr/bin/top -n 1 | /usr/bin/head -n5 > ./others/sysinfo" );
	// std::ifstream				ifs("./others/sysinfo");
	// std::string					line = "";
	// std::vector<std::string> 	info;

	// while (getline(ifs, line, ' '))
	// 	info.push_back(line);

	// ifs.close();

	// std::string process_total = info.at(1);
	// std::string process_running = info.at(3);
	// std::string process_stuck = info.at(5);
	// std::string process_sleeping = info.at(7);
	// std::string process_threads = info.at(9);

	// std::string load_avg1;
	// std::string load_avg2;
	// std::string load_avg3;

	// int stuck = 0;

	// if (info.at(6) == "stuck,")
	// 	stuck = 1;

	// if (stuck == 1)
	// {
	// 	load_avg1 = info.at(14);
	// 	load_avg2 = info.at(15);
	// 	load_avg3 = info.at(16);
	// }
	// else
	// {
	// 	load_avg1 = info.at(12);
	// 	load_avg2 = info.at(13);
	// 	load_avg3 = info.at(14);
	// }

	// std::cout << "PROCESSES" << std::endl <<
	// 	"Total: " << process_total << std::endl <<
	// 	"Running: " << process_running << std::endl;
	// if (stuck == 1)
	// {
	// 	std::cout << "Stuck: " << process_stuck << std::endl << 
	// 	"Sleeping: " << process_sleeping << std::endl <<
	// 	"Threads: " << process_threads << std::endl << std::endl;
	// }
	// else
	// {
	// 	std::cout << "Sleeping: " << process_stuck << std::endl << 
	// 	"Threads: " << process_sleeping << std::endl << std::endl;
	// }

	// std::cout << "COMPUTATIONAL LOAD AVG" << std::endl <<
	// 	load_avg1 << " " << load_avg2 << " " << load_avg3 << std::endl << std::endl;

	// /*
	// ** RAM
	// */
	// std::system( "top -l 1 | grep -E \"^CPU|^Phys\" > ./others/raminfo" );
	// std::ifstream				rifs("./others/raminfo");
	// std::string					rline = "";
	// std::vector<std::string>	ram;

	// while (getline(rifs, rline, ' '))
	// 	ram.push_back(rline);

	// rifs.close();

	// std::string cpu_usage_user = ram.at(2);
	// std::string cpu_usage_sys = ram.at(4);
	// std::string cpu_usage_idle = ram.at(6);

	// long ram_used = stoi(ram.at(9));
	// long ram_wired = stoi(ram.at(11).substr(1, ram.at(11).length()));
	// long ram_unused = stoi(ram.at(13));

	// std::cout << "CPU USAGE" << std::endl <<
	// 	"User: " << cpu_usage_user << std::endl <<
	// 	"System: " << cpu_usage_sys << std::endl <<
	// 	"Idle: " << cpu_usage_idle << std::endl << std::endl;

	// std::cout << "RAM" << std::endl <<
	// 	"Max Capacity: 8192MB" << std::endl <<
	// 	"Used: " << (ram_used - ram_wired) << "MB" << std::endl <<
	// 	"Wired: " << ram_wired << "MB" << std::endl <<
	// 	"Unused: " << ram_unused << "MB" << std::endl;

	// /*
	// ** Network throughput
	// */
	// std::system( "nettop -J bytes_in,bytes_out -x -l1 > ./others/netinfo" );
	// std::ifstream				nifs("./others/netinfo");
	// std::string					nline = "";
	// std::vector<std::string>			net;

	// long	packet_in = 0;
	// long	packet_out = 0;
	// int		i = 0;

	// while (getline(nifs, nline, ' '))
	// {
	// 	if (nline != "" && (nline.find_first_not_of("0123456789") == std::string::npos))
	// 	{
	// 		if (i % 2 == 0)
	// 			packet_in = packet_in + stol(nline);
	// 		else
	// 			packet_out = packet_out + stol(nline);
	// 		i++;
	// 	}
	// }

	// std::cout << std::endl << "NETWORK THROUGHPUT" << std::endl <<
	// 	"Packets In: " << packet_in << std::endl << 
	// 	"Packets Out: " << packet_out << std::endl;

	// rifs.close();
	sleep(5);
	endwin();
}





















