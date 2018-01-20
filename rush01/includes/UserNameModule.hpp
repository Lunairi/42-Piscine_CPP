/* ************************************************************************** */
/*                                                                            */
/*    UserNameModule.hpp     _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */


#ifndef USERNAMEMODULE_HPP
# define USERNAMEMODULE_HPP

# include <Gkrellm.hpp>

class UserNameModule : public IMonitorModule
{
	public:

		UserNameModule(std::string const name);
		virtual ~UserNameModule(void);
		
		void				tick(void);
		std::string const	&getOutput(void) const;
		std::string const	&getName(void) const;
		
	private:

		UserNameModule(void);
		UserNameModule(UserNameModule const &obj);
		UserNameModule	&operator=(UserNameModule const &r);

		std::string			_output;
		std::string			_name;
	
};

#endif