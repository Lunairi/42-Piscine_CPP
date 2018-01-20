/* ************************************************************************** */
/*                                                                            */
/*    DateTimeModule.cpp     _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */


#include <Gkrellm.hpp>

DateTimeModule::DateTimeModule(std::string const name) : IMonitorModule(), _output(), _name(name)
{
	std::string	month[] = 
	{
		"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug",
		"Sep", "Oct", "Nov", "Dec"
	};

	std::string	week[] =
	{
		"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
	};

	time_t  timev = time(&timev);
	struct tm *stamp = localtime(&timev);
	std::stringstream convert;
	convert << week[stamp->tm_wday] << " " << month[stamp->tm_mon] << " " <<
		stamp->tm_mday << ", " << (1900 + stamp->tm_year);
	this->_output.push_back(convert.str());
	convert.str("");
	convert << stamp->tm_hour << ":";
	if (stamp->tm_min > 9)
		convert << stamp->tm_min << ":";
	else
		convert << "0" << stamp->tm_min << ":";
	if (stamp->tm_sec > 9)
		convert << stamp->tm_sec;	
	else
		convert << "0" << stamp->tm_sec;
	this->_output.push_back(convert.str());

	return ;
}

DateTimeModule::~DateTimeModule()
{
	return ;
}

std::vector<std::string> const		&DateTimeModule::getOutput(void) const
{
	return (this->_output);
}

std::string const					&DateTimeModule::getName(void) const
{
	return (this->_name);
}

void								DateTimeModule::tick(void)
{
	time_t  timev = time(&timev);
	struct tm *stamp = localtime(&timev);
	std::stringstream convert;
	convert << stamp->tm_hour << ":";
	if (stamp->tm_min > 9)
		convert << stamp->tm_min << ":";
	else
		convert << "0" << stamp->tm_min << ":";
	if (stamp->tm_sec > 9)
		convert << stamp->tm_sec;	
	else
		convert << "0" << stamp->tm_sec;
	this->_output.at(1) = convert.str();

	return ;
}
