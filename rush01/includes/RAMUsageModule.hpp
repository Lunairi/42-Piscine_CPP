/* ************************************************************************** */
/*                                                                            */
/*    RAMUsageModule.hpp     _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */


#ifndef RAMUSAGEMODULE_HPP
# define RAMUSAGEMODULE_HPP

# include <Gkrellm.hpp>

class RAMUsageModule : public IMonitorModule
{
	public:

		RAMUsageModule(std::string const name);
		virtual ~RAMUsageModule(void);
		
		void							tick(void);
		std::vector<std::string> const	&getOutput(void) const;
		std::string const				&getName(void) const;
		
	private:

		RAMUsageModule(void);
		RAMUsageModule(RAMUsageModule const &obj);
		RAMUsageModule	&operator=(RAMUsageModule const &r);

		std::vector<std::string>		_output;
		std::string						_name;
	
};

#endif