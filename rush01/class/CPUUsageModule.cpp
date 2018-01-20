/* ************************************************************************** */
/*                                                                            */
/*    CPUUsageModule.cpp     _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */


#include <Gkrellm.hpp>

CPUUsageModule::CPUUsageModule(std::string const name) : IMonitorModule(), _output(), _name(name)
{
	std::system( "top -l 1 | grep -E \"^CPU|^Phys\" > ./others/raminfo" );
	std::ifstream				rifs("./others/raminfo");
	std::string					rline = "";
	std::vector<std::string>	cpu;

	while (getline(rifs, rline, ' '))
		cpu.push_back(rline);

	rifs.close();

	std::stringstream 			convert;

	convert << "User: " << cpu.at(2) << "%";
	this->_output.push_back(convert.str());
	convert.str("");

	convert << "System: " << cpu.at(4) << "%";
	this->_output.push_back(convert.str());
	convert.str("");

	convert << "Idle: " << cpu.at(6) << "%";
	this->_output.push_back(convert.str());

	return ;
}

CPUUsageModule::~CPUUsageModule()
{
	return ;
}

std::vector<std::string> const		&CPUUsageModule::getOutput(void) const
{
	return (this->_output);
}

std::string const					&CPUUsageModule::getName(void) const
{
	return (this->_name);
}

void								CPUUsageModule::tick(void)
{
	std::system( "top -l 1 | grep -E \"^CPU|^Phys\" > ./others/raminfo" );
	std::ifstream				rifs("./others/raminfo");
	std::string					rline = "";
	std::vector<std::string>	cpu;

	while (getline(rifs, rline, ' '))
		cpu.push_back(rline);

	rifs.close();

	std::stringstream 			convert;

	convert << "User: " << cpu.at(2) << "%";
	this->_output.at(0) = convert.str();
	convert.str("");

	convert << "System: " << cpu.at(4) << "%";
	this->_output.at(1) = convert.str();
	convert.str("");

	convert << "Idle: " << cpu.at(6) << "%";
	this->_output.at(2) = convert.str();
	return ;
}
