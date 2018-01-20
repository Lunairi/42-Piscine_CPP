/* ************************************************************************** */
/*                                                                            */
/*    HostNameModule.hpp     _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */


#ifndef HOSTNAMEMODULE_HPP
# define HOSTNAMEMODULE_HPP

# include <Gkrellm.hpp>

class HostNameModule : public IMonitorModule
{
	public:

		HostNameModule(std::string const name);
		virtual ~HostNameModule(void);
		
		void							tick(void);
		std::vector<std::string> const	&getOutput(void) const;
		std::string const				&getName(void) const;
		
	private:

		HostNameModule(void);
		HostNameModule(HostNameModule const &obj);
		HostNameModule	&operator=(HostNameModule const &r);

		std::vector<std::string>		_output;
		std::string						_name;
	
};

#endif