/* ************************************************************************** */
/*                                                                            */
/*    RobotomyRequestForm.cpp              _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form(target, 72, 45)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &obj) : Form(obj.getName(), 72, 45)
{
	*this = obj;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &r) 
{
	(void)r;
	return (*this);
}

void					RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	static int i = 0;

	if ((this->getSigned() == true) && (executor.getGrade() <= this->getEGrade()))
	{
		system("afplay Drill.mp3 &");
		std::cout << "* Bzzt... BZZZT... VrrrrRrRRRRRrrrr... *" << std::endl;
		if (i % 2 == 0)
			std::cout << executor.getName() << " has been robotomized successfully" << std::endl;
		else
			std::cout << executor.getName() << " has failed to be robotomized" << std::endl;
		i = i + 1;
	}
	else if (this->getSigned() == false)
		std::cout << "A Bureaucrat must signed this form first before it can be requested." << std::endl;
	else
		throw Form::GradeTooLowException();
	return;
}

std::ostream			&operator<<(std::ostream &o, RobotomyRequestForm const &r)
{
	o << "Robotomy Request Form Details:" << std::endl
			<< "Name: " << r.getName() << std::endl
			<< "Signing Grade Requirement: " << r.getSGrade() << std::endl
			<< "Execution Grade Requirement: " << r.getEGrade() << std::endl;
	if(r.getSigned())
			o << "Form has been signed." << std::endl;
	else
			o << "Form has not been signed yet." << std::endl;
	return (o);
}