/* ************************************************************************** */
/*                                                                            */
/*    NetworkInfoModule.cpp  _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */


#include <Gkrellm.hpp>

NetworkInfoModule::NetworkInfoModule(std::string const name) : IMonitorModule(), _output(), _name(name)
{
	std::system("nettop -J bytes_in,bytes_out -x -l1 > ./others/netinfo");
	std::ifstream				nifs("./others/netinfo");
	std::string					nline = "";
	std::vector<std::string>			net;

	long	packet_in = 0;
	long	packet_out = 0;
	int		i = 0;

	while (getline(nifs, nline, ' '))
	{
		if (nline != "" && (nline.find_first_not_of("0123456789") == std::string::npos))
		{
			if (i % 2 == 0)
				packet_in = packet_in + stol(nline);
			else
				packet_out = packet_out + stol(nline);
			i++;
		}
	}

	std::stringstream 			convert;

	convert << "Packets In: " << packet_in;
	this->_output.push_back(convert.str());
	convert.str("");

	convert << "Packets Out: " << packet_out;
	this->_output.push_back(convert.str());

	nifs.close();

	return ;
}

NetworkInfoModule::~NetworkInfoModule()
{
	return ;
}

std::vector<std::string> const		&NetworkInfoModule::getOutput(void) const
{
	return (this->_output);
}

std::string const					&NetworkInfoModule::getName(void) const
{
	return (this->_name);
}

void								NetworkInfoModule::tick(void)
{
	std::system("nettop -J bytes_in,bytes_out -x -l1 > ./others/netinfo");
	std::ifstream				nifs("./others/netinfo");
	std::string					nline = "";
	std::vector<std::string>			net;

	long	packet_in = 0;
	long	packet_out = 0;
	int		i = 0;

	while (getline(nifs, nline, ' '))
	{
		if (nline != "" && (nline.find_first_not_of("0123456789") == std::string::npos))
		{
			if (i % 2 == 0)
				packet_in = packet_in + stol(nline);
			else
				packet_out = packet_out + stol(nline);
			i++;
		}
	}

	std::stringstream 			convert;

	convert << "Packets In: " << packet_in;
	this->_output.at(0) = convert.str();
	convert.str("");

	convert << "Packets Out: " << packet_out;
	this->_output.at(1) = convert.str();

	nifs.close();

	return ;
}
