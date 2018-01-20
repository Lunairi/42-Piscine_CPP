/* ************************************************************************** */
/*                                                                            */
/*    DateTimeModule.hpp     _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */


#ifndef DATETIMEMODULE_HPP
# define DATETIMEMODULE_HPP

# include <Gkrellm.hpp>

class DateTimeModule : public IMonitorModule
{
	public:

		DateTimeModule(std::string const name);
		virtual ~DateTimeModule(void);
		
		void							tick(void);
		std::vector<std::string> const	&getOutput(void) const;
		std::string const				&getName(void) const;
		
	private:

		DateTimeModule(void);
		DateTimeModule(DateTimeModule const &obj);
		DateTimeModule	&operator=(DateTimeModule const &r);

		std::vector<std::string>		_output;
		std::string						_name;
	
};

#endif