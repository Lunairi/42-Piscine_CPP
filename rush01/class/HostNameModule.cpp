/* ************************************************************************** */
/*                                                                            */
/*    HostNameModule.cpp     _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */


#include <Gkrellm.hpp>

HostNameModule::HostNameModule(std::string const name) : IMonitorModule(), _output(), _name(name)
{
	char hostname[255]; // 255 is max len on linux
	gethostname(hostname, 255);

	this->_output = hostname;
	return ;
}

HostNameModule::~HostNameModule()
{
	return ;
}

std::string const		&HostNameModule::getOutput(void) const
{
	return (this->_output);
}

std::string const		&HostNameModule::getName(void) const
{
	return (this->_name);
}

void					HostNameModule::tick(void)
{
	return ;
}
