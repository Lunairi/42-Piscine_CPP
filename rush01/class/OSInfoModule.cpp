/* ************************************************************************** */
/*                                                                            */
/*    OSInfoModule.cpp       _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#include <Gkrellm.hpp>

OSInfoModule::OSInfoModule(std::string const name) : IMonitorModule(), _output(), _name(name)
{
	struct utsname	uts;
	uname(&uts);

	this->_output.push_back(uts.sysname);
	this->_output.push_back(uts.release);
	return ;
}

OSInfoModule::~OSInfoModule()
{
	return ;
}

std::vector<std::string> const		&OSInfoModule::getOutput(void) const
{
	return (this->_output);
}

std::string const					&OSInfoModule::getName(void) const
{
	return (this->_name);
}

void								OSInfoModule::tick(void)
{
	return ;
}
