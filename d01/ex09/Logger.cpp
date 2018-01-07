/* ************************************************************************** */
/*                                                                            */
/*    Logger.cpp             _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "Logger.hpp"


Logger::Logger()
{
	return;
}

Logger::~Logger()
{
	return;
}

void	Logger::log(std::string const &dest, std::string const &message)
{
	std::string msg;
	msg = makeLogEntry(message);

	int i = 0;

	void (Logger::*ptr[])(std::string const &) =
	{
		&Logger::logToConsole,
		&Logger::logToConsole,
		&Logger::logToFile,
		&Logger::logToFile

	};

	std::string commands[] =
	{
		"console",
		"Console",
		"file",
		"File"
	};

	while (i < 4)
	{
		if (commands[i] == dest)
		{
			(this->*ptr[i])(msg);
			i = 5;
		}
		i++;
	}
	return;
}

void	Logger::logToConsole(std::string const &input)
{
	std::cout << input;
	return;
}

void	Logger::logToFile(std::string const &input)
{
	std::string		file = "Logger";
	std::ifstream	ifs(file);
	std::string		line = "";
	std::string		ofile = "";
	int				i = 0;

	if (ifs.is_open())
	{
		while (getline(ifs, line))
		{
			if (i != 0)
				ofile = ofile + '\n';
			ofile = ofile + line;
			i++;
		}
		i = 0;
	}
	else
		i = -1;
	std::ofstream	ofs(file);
	if (i == -1)
		ofs << input;
	else
		ofs << ofile << std::endl << input;
	ofs.close();
	return;
}

std::string	Logger::makeLogEntry(std::string input)
{
	time_t	timev = time(&timev);
	struct tm *stamp = localtime(&timev);
	std::ostringstream timestamp;

	timestamp << "[" << (1900 + stamp->tm_year) << "-";
	if (stamp->tm_mon >= 9)
		timestamp << (stamp->tm_mon + 1) << "-";
	else
		timestamp << "0" << (stamp->tm_mon + 1) << "-";
	if (stamp->tm_mday > 9)
		timestamp << stamp->tm_mday;
	else
		timestamp << "0" << (stamp->tm_mday);
	if (stamp->tm_hour > 9)
		timestamp << " " << stamp->tm_hour << ":";
	else
		timestamp << " 0" << stamp->tm_hour << ":";
	if (stamp->tm_min > 9)
		timestamp << stamp->tm_min << ":";
	else
		timestamp << "0" << stamp->tm_min << ":";
	if (stamp->tm_sec > 9)
		timestamp << stamp->tm_sec << "]";
	else
		timestamp << "0" << stamp->tm_sec << "]";
	timestamp << " " << input;
	std::string logtime(timestamp.str());
	return (logtime);
}
