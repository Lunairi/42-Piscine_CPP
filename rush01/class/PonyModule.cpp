/* ************************************************************************** */
/*                                                                            */
/*    PonyModule.cpp         _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#include <Gkrellm.hpp>

PonyModule::PonyModule(std::string const name) : IMonitorModule(), _output(), _name(name)
{
	
	this->_output.push_back("             .'' ");
	this->_output.push_back("   ._.-.___.' (`\\ ");
	this->_output.push_back("  //(        ( `' ");
	this->_output.push_back(" '/ )\\ ).__. ) ");
	this->_output.push_back(" ' <' `\\ ._/'\\ ");
	this->_output.push_back("    `   \\     \\ ");

	return ;
}

PonyModule::~PonyModule()
{
	return ;
}

std::vector<std::string> const		&PonyModule::getOutput(void) const
{
	return (this->_output);
}

std::string const					&PonyModule::getName(void) const
{
	return (this->_name);
}

void								PonyModule::tick(void)
{
	return ;
}