/* ************************************************************************** */
/*                                                                            */
/*    OSInfoModule.hpp       _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */


#ifndef OSINFOMODULE_HPP
# define OSINFOMODULE_HPP

# include <Gkrellm.hpp>

class OSInfoModule : public IMonitorModule
{
	public:

		OSInfoModule(std::string const name);
		virtual ~OSInfoModule(void);
		
		void							tick(void);
		std::vector<std::string> const	&getOutput(void) const;
		std::string const				&getName(void) const;
		
	private:

		OSInfoModule(void);
		OSInfoModule(OSInfoModule const &obj);
		OSInfoModule	&operator=(OSInfoModule const &r);

		std::vector<std::string>		_output;
		std::string						_name;
	
};

#endif