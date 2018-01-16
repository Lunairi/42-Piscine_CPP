/* ************************************************************************** */
/*                                                                            */
/*    PresidentialPardonForm.cpp           _              :::      ::::::::   */
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
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form(target, 72, 45)
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &obj) : Form(obj.getName(), 72, 45)
{
	*this = obj;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &r) 
{
	(void)r;
	return (*this);
}

void					PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if ((this->getSigned() == true) && (executor.getGrade() <= this->getEGrade()))
		std::cout << executor.getName() << " has been pardoned by Zafod Beeblebrox" << std::endl;
	else if (this->getSigned() == false)
		std::cout << "A Bureaucrat must signed this form first before it can be requested." << std::endl;
	else
		throw Form::GradeTooLowException();
	return;
}

std::ostream			&operator<<(std::ostream &o, PresidentialPardonForm const &r)
{
	o << "Presidential Pardon Form Details:" << std::endl
			<< "Name: " << r.getName() << std::endl
			<< "Signing Grade Requirement: " << r.getSGrade() << std::endl
			<< "Execution Grade Requirement: " << r.getEGrade() << std::endl;
	if(r.getSigned())
			o << "Form has been signed." << std::endl;
	else
			o << "Form has not been signed yet." << std::endl;
	return (o);
}