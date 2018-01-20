/* ************************************************************************** */
/*                                                                            */
/*    ProcessInfoModule.hpp  _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */


#ifndef PROCESSINFOMODULE_HPP
# define PROCESSINFOMODULE_HPP

# include <Gkrellm.hpp>

class ProcessInfoModule : public IMonitorModule
{
	public:

		ProcessInfoModule(std::string const name);
		virtual ~ProcessInfoModule(void);
		
		void							tick(void);
		std::vector<std::string> const	&getOutput(void) const;
		std::string const				&getName(void) const;
		
	private:

		ProcessInfoModule(void);
		ProcessInfoModule(ProcessInfoModule const &obj);
		ProcessInfoModule	&operator=(ProcessInfoModule const &r);

		std::vector<std::string>		_output;
		std::string						_name;
	
};

#endif