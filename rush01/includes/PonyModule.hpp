/* ************************************************************************** */
/*                                                                            */
/*    PonyModule.hpp         _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef PONYMODULE_HPP
# define PONYMODULE_HPP

# include <Gkrellm.hpp>

class PonyModule : public IMonitorModule
{
	public:

		PonyModule(std::string const name);
		virtual ~PonyModule(void);
		
		void							tick(void);
		std::vector<std::string> const	&getOutput(void) const;
		std::string const				&getName(void) const;
		
	private:

		PonyModule(void);
		PonyModule(PonyModule const &obj);
		PonyModule	&operator=(PonyModule const &r);

		std::vector<std::string>		_output;
		std::string						_name;
	
};

#endif