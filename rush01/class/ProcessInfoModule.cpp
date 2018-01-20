/* ************************************************************************** */
/*                                                                            */
/*    ProcessInfoModule.cpp  _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */


#include <Gkrellm.hpp>

ProcessInfoModule::ProcessInfoModule(std::string const name) : IMonitorModule(), _output(), _name(name)
{
	std::system( "/usr/bin/top -n 1 | /usr/bin/head -n5 > ./others/sysinfo" );
	std::ifstream				ifs("./others/sysinfo");
	std::string					line = "";
	std::vector<std::string> 	info;

	while (getline(ifs, line, ' '))
		info.push_back(line);

	ifs.close();

	this->_output.push_back(info.at(1));
	this->_output.push_back(info.at(3));
	this->_output.push_back(info.at(5));
	this->_output.push_back(info.at(7));
	this->_output.push_back(info.at(9));

	std::string load_avg1;
	std::string load_avg2;
	std::string load_avg3;

	int stuck = 0;

	if (info.at(6) == "stuck,")
		stuck = 1;

	if (stuck == 1)
	{
		this->_output.push_back(info.at(14));
		this->_output.push_back(info.at(15));
		this->_output.push_back(info.at(16));
	}
	else
	{
		this->_output.push_back(info.at(12));
		this->_output.push_back(info.at(13));
		this->_output.push_back(info.at(14));
	}

	return ;
}

ProcessInfoModule::~ProcessInfoModule()
{
	return ;
}

std::vector<std::string> const		&ProcessInfoModule::getOutput(void) const
{
	return (this->_output);
}

std::string const					&ProcessInfoModule::getName(void) const
{
	return (this->_name);
}

void								ProcessInfoModule::tick(void)
{
	return ;
}
