/* ************************************************************************** */
/*                                                                            */
/*    RobotomyRequestForm.hpp            _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class	RobotomyRequestForm : public Form
{

	public:

		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm &obj);
		virtual ~RobotomyRequestForm(void);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &r);

		void	execute(Bureaucrat const &executor) const;
}; 

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm const &r); 

#endif