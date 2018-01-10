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

#ifndef LOGGER_H
# define LOGGER_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>

class	Logger 
{

	public:

		Logger(void);
		~Logger(void);

		void			log(std::string const &dest, std::string const &message);

	private:

		void			logToConsole(std::string const &input);
		void			logToFile(std::string const &input);
		std::string		makeLogEntry(std::string message);


}; 

#endif