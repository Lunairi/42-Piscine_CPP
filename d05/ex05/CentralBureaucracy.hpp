/* ************************************************************************** */
/*                                                                            */
/*    CentralBureaucracy.hpp _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef CENTRALBUREAUCRACY_H
# define CENTRALBUREAUCRACY_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

class	CentralBureaucracy
{

	public:

		CentralBureaucracy(void);
		CentralBureaucracy(CentralBureaucracy &obj);
		virtual ~CentralBureaucracy(void);
		CentralBureaucracy &operator=(CentralBureaucracy &r);

		void	feedSigner(Bureaucrat &obj);
		void	feedExecuter(Bureaucrat &obj);

		void	queueUp(std::string obj);

		void	doBureaucracy(void);

	private:

		OfficeBlock		_ob[20];
		std::string		_target[100];
}; 

#endif