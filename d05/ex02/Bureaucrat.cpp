/* ************************************************************************** */
/*                                                                            */
/*    Bureaucrat.cpp         _             _              :::      ::::::::   */
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
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat &obj)
{
	*this = obj;
	return;
}

Bureaucrat::~Bureaucrat(void)
{
	return;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &r) 
{
	this->_grade = r._grade;
	return (*this);
}

void					Bureaucrat::executeForm(Form const &form)
{
	if (this->_grade < form.getEGrade())
	{
		std::cout << "Bureaucrat " << this->_name << " executes " << form.getName() << std::endl;
		form.execute(*this);
	}
	else
		std::cout << "Bureaucrat " << this->_name << " grade is too low (" << this->_grade << "). They need a grade of "
			<< form.getEGrade() << " to execute " << form.getName() << std::endl;
	return;
}

std::string 			Bureaucrat::getName(void) const
{
	return (this->_name);
}

int						Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void					Bureaucrat::operator-=(int const i)
{
	if ((this->_grade + i) > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = this->_grade + i;
}

void					Bureaucrat::operator+=(int const i)
{
	if ((this->_grade - i) < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = this->_grade - i;
}

std::ostream			&operator<<(std::ostream &o, Bureaucrat const &r)
{
	o << "[" << r.getName() << "], bureaucrat grade [" << r.getGrade() << "]" << std::endl;
	return (o);
}

/*
** GradeTooHighException Nested Class
*/

Bureaucrat::GradeTooHighException::GradeTooHighException(void)
{
	return;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const &obj)
{
	*this = obj;
	return;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw()
{
	return;
}

Bureaucrat::GradeTooHighException &Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const &r) 
{
	(void)r;
	return (*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: Grade too high (<1)");
}

/*
** GradeTooLowException Nested Class
*/

Bureaucrat::GradeTooLowException::GradeTooLowException(void)
{
	return;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const &obj)
{
	*this = obj;
	return;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw()
{
	return;
}

Bureaucrat::GradeTooLowException &Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const &r) 
{
	(void)r;
	return (*this);
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: Grade too low (>150)");
}