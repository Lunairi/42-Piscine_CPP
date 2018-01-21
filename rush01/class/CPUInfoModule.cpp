/* ************************************************************************** */
/*                                                                            */
/*    CPUInfoModule.cpp      _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */


#include <Gkrellm.hpp>

CPUInfoModule::CPUInfoModule(std::string const name) : IMonitorModule(), _output(), _name(name)
{
	char buf[128];
	size_t buflen = 128;
	sysctlbyname("machdep.cpu.brand_string", &buf, &buflen, NULL, 0);
	std::string convert = buf;
	this->_output.push_back(convert.substr(0, convert.find("M) ") + 2));
	this->_output.push_back(convert.substr(convert.find("M) ") + 3, convert.length()));

	return ;
}

CPUInfoModule::~CPUInfoModule()
{
	return ;
}

std::vector<std::string> const		&CPUInfoModule::getOutput(void) const
{
	return (this->_output);
}

std::string const					&CPUInfoModule::getName(void) const
{
	return (this->_name);
}

void								CPUInfoModule::tick(void)
{
	return ;
}
