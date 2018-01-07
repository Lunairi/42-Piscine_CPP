/* ************************************************************************** */
/*                                                                            */
/*    Logger.hpp             _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <fstream>
#include <string>

class	Logger 
{

	public:

		Logger();
		~Logger();

		void			log(std::string const & dest, std::string const & message);

	private:
		
		void			logToConsole(std::string input);
		void			logToFile(std::string input);
		std::string		makeLogEntry(std::string message);


}; 

#endif