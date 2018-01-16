/* ************************************************************************** */
/*                                                                            */
/*    Form.cpp               _             _              :::      ::::::::   */
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
#include "Form.hpp"

Form::Form(std::string const name, int sgrade, int egrade) : _name(name), _signed(false), _sgrade(sgrade), _egrade(egrade)
{
	if (sgrade < 1 || egrade < 1)
		throw Form::GradeTooHighException();
	else if (sgrade > 150 || egrade > 150)
		throw Form::GradeTooLowException();
	return;
}

Form::Form(Form &obj) : _sgrade(obj._sgrade), _egrade(obj._egrade)
{
	*this = obj;
	return;
}

Form::~Form(void)
{
	return;
}

Form &Form::operator=(Form const &r) 
{
	this->_signed = r._signed;
	return (*this);
}

void				Form::signForm(void) 
{
	this->_signed = true;
	return;
}

void				Form::beSigned(Bureaucrat &r)
{
	if (r.getGrade() > this->_sgrade)
	{
		std::cout << "<Bureaucrat " << r.getName() << "> cannot sign <" << this->_name << "> because ";
		throw Form::GradeTooLowException();
	}
	else
	{
		if (this->_signed)
			std::cout << "<Bureaucrat " << r.getName() << "> cannot sign <" << this->_name << "> because form is already signed" << std::endl;
		else
		{
			std::cout << "<Bureaucrat " << r.getName() << "> signs <" << this->_name << ">" << std::endl;
			signForm();
		}
	}

}

std::string			Form::getName(void) const
{
	return (this->_name);
}

bool				Form::getSigned(void) const
{
	return (this->_signed);
}

int					Form::getSGrade(void) const
{
	return (this->_sgrade);
}

int					Form::getEGrade(void) const
{
	return	(this->_egrade);
}

std::ostream			&operator<<(std::ostream &o, Form const &r)
{
	o << "Form Details:" << std::endl
			<< "Name: " << r.getName() << std::endl
			<< "Signing Grade Requirement: " << r.getSGrade() << std::endl
			<< "Execution Grade Requirement: " << r.getEGrade() << std::endl;
	if(r.getSigned())
			o << "Form has been signed." << std::endl;
	else
			o << "Form has not been signed yet." << std::endl;
	return (o);
}

/*
** GradeTooHighException Nested Class
*/

Form::GradeTooHighException::GradeTooHighException(void)
{
	return;
}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const &obj)
{
	*this = obj;
	return;
}

Form::GradeTooHighException::~GradeTooHighException(void) throw()
{
	return;
}

Form::GradeTooHighException &Form::GradeTooHighException::operator=(GradeTooHighException const &r) 
{
	(void)r;
	return (*this);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form Error: Grade too high");
}

/*
** GradeTooLowException Nested Class
*/

Form::GradeTooLowException::GradeTooLowException(void)
{
	return;
}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const &obj)
{
	*this = obj;
	return;
}

Form::GradeTooLowException::~GradeTooLowException(void) throw()
{
	return;
}

Form::GradeTooLowException &Form::GradeTooLowException::operator=(GradeTooLowException const &r) 
{
	(void)r;
	return (*this);
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form Error: Grade too low");
}