/* ************************************************************************** */
/*                                                                            */
/*    IMonitorModule.hpp     _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

# include <Gkrellm.hpp>

class IMonitorModule
{
	public:

		IMonitorModule(void) {}
		virtual ~IMonitorModule(void) {}

		virtual void							tick(void) = 0;
		virtual std::vector<std::string> const	&getOutput(void) const = 0;
		virtual std::string const				&getName(void) const = 0;
		
	private:

		IMonitorModule(IMonitorModule const &obj);
		IMonitorModule	&operator=(IMonitorModule const &r);
};

#endif