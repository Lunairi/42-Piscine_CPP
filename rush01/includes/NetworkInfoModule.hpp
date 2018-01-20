/* ************************************************************************** */
/*                                                                            */
/*    NetworkInfoModule.hpp  _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */


#ifndef NetworkInfoMODULE_HPP
# define NetworkInfoMODULE_HPP

# include <Gkrellm.hpp>

class NetworkInfoModule : public IMonitorModule
{
	public:

		NetworkInfoModule(std::string const name);
		virtual ~NetworkInfoModule(void);
		
		void							tick(void);
		std::vector<std::string> const	&getOutput(void) const;
		std::string const				&getName(void) const;
		
	private:

		NetworkInfoModule(void);
		NetworkInfoModule(NetworkInfoModule const &obj);
		NetworkInfoModule	&operator=(NetworkInfoModule const &r);

		std::vector<std::string>		_output;
		std::string						_name;
	
};

#endif