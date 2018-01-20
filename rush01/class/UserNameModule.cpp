/* ************************************************************************** */
/*                                                                            */
/*    UserNameModule.cpp     _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */


#include <Gkrellm.hpp>

UserNameModule::UserNameModule(std::string const name) : IMonitorModule(), _output(), _name(name)
{
	char username[255]; // 255 is max len on linux
	getlogin_r(username, 255);

	this->_output = username;
	return ;
}

UserNameModule::~UserNameModule()
{
	return ;
}

std::string const		&UserNameModule::getOutput(void) const
{
	return (this->_output);
}

std::string const		&UserNameModule::getName(void) const
{
	return (this->_name);
}

void					UserNameModule::tick(void)
{
	return ;
}
