/* ************************************************************************** */
/*                                                                            */
/*    RAMUsageModule.cpp     _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */


#include <Gkrellm.hpp>

RAMUsageModule::RAMUsageModule(std::string const name) : IMonitorModule(), _output(), _name(name)
{
	std::system( "top -l 1 | grep -E \"^CPU|^Phys\" > ./others/raminfo" );
	std::ifstream				rifs("./others/raminfo");
	std::string					rline = "";
	std::vector<std::string>	ram;

	while (getline(rifs, rline, ' '))
		ram.push_back(rline);

	rifs.close();

	std::stringstream 			convert;

	convert << "Max Capacity: 8192MB";
	this->_output.push_back(convert.str());
	convert.str("");

	convert << "Used: " << (stoi(ram.at(9)) -  stoi(ram.at(11).substr(1, ram.at(11).length()))) << "MB";
	this->_output.push_back(convert.str());
	convert.str("");

	convert << "Wired :" << stoi(ram.at(11).substr(1, ram.at(11).length())) << "MB";
	this->_output.push_back(convert.str());
	convert.str("");

	convert << "Unused: " << stoi(ram.at(13)) << "MB";
	this->_output.push_back(convert.str());

	return ;
}

RAMUsageModule::~RAMUsageModule()
{
	return ;
}

std::vector<std::string> const		&RAMUsageModule::getOutput(void) const
{
	return (this->_output);
}

std::string const					&RAMUsageModule::getName(void) const
{
	return (this->_name);
}

void								RAMUsageModule::tick(void)
{
	std::system( "top -l 1 | grep -E \"^CPU|^Phys\" > ./others/raminfo" );
	std::ifstream				rifs("./others/raminfo");
	std::string					rline = "";
	std::vector<std::string>	ram;

	while (getline(rifs, rline, ' '))
		ram.push_back(rline);

	rifs.close();

	std::stringstream 			convert;

	convert << "Used: " << (stoi(ram.at(9)) -  stoi(ram.at(11).substr(1, ram.at(11).length()))) << "MB";
	this->_output.at(1) = convert.str();
	convert.str("");

	convert << "Wired :" << stoi(ram.at(11).substr(1, ram.at(11).length())) << "MB";
	this->_output.at(2) = convert.str();
	convert.str("");

	convert << "Unused: " << stoi(ram.at(13)) << "MB";
	this->_output.at(3) = convert.str();
	return ;
}
