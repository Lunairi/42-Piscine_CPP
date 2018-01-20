/* ************************************************************************** */
/*                                                                            */
/*    CPUInfoModule.hpp      _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */


#ifndef CPUINFOMODULE_HPP
# define CPUINFOMODULE_HPP

# include <Gkrellm.hpp>

class CPUInfoModule : public IMonitorModule
{
	public:

		CPUInfoModule(std::string const name);
		virtual ~CPUInfoModule(void);
		
		void							tick(void);
		std::vector<std::string> const	&getOutput(void) const;
		std::string const				&getName(void) const;
		
	private:

		CPUInfoModule(void);
		CPUInfoModule(CPUInfoModule const &obj);
		CPUInfoModule	&operator=(CPUInfoModule const &r);

		std::vector<std::string>		_output;
		std::string						_name;
	
};

#endif