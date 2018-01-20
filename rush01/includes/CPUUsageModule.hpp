/* ************************************************************************** */
/*                                                                            */
/*    CPUUsageModule.hpp     _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */


#ifndef CPUUSAGEMODULE_HPP
# define CPUUSAGEMODULE_HPP

# include <Gkrellm.hpp>

class CPUUsageModule : public IMonitorModule
{
	public:

		CPUUsageModule(std::string const name);
		virtual ~CPUUsageModule(void);
		
		void							tick(void);
		std::vector<std::string> const	&getOutput(void) const;
		std::string const				&getName(void) const;
		
	private:

		CPUUsageModule(void);
		CPUUsageModule(CPUUsageModule const &obj);
		CPUUsageModule	&operator=(CPUUsageModule const &r);

		std::vector<std::string>		_output;
		std::string						_name;
	
};

#endif