/* ************************************************************************** */
/*                                                                            */
/*    Intern.cpp             _             _              :::      ::::::::   */
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
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void)
{
	return;
}

Intern::Intern(Intern &obj)
{
	*this = obj;
	return;
}

Intern::~Intern(void)
{
	return;
}

Intern &Intern::operator=(Intern const &r) 
{
	(void)r;
	return (*this);
}

Form		*Intern::makeForm(std::string form, std::string target)
{
	if (form == "shrubbery creation" || form == "Shrubbery Creation")
	{
		std::cout << "Intern creates " << form << std::endl;
		return (new ShrubberyCreationForm(target));
	}
	else if (form == "robotomy request" || form == "Robotomy Request")
	{
		std::cout << "Intern creates " << form << std::endl;
		return (new RobotomyRequestForm(target));
	}
	else if (form == "presidential pardon" || form == "Presidential Pardon")
	{
		std::cout << "Intern creates " << form << std::endl;
		return (new PresidentialPardonForm(target));
	}
	else
		std::cout << "Itern failed to create " << form << std::endl;
	return (NULL);
}
