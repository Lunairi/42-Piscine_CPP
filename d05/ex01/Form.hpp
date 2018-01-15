/* ************************************************************************** */
/*                                                                            */
/*    Form.hpp               _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "Bureaucrat.hpp"

class	Form
{

	public:

		Form(void);
		Form(std::string const name, int sgrade, int egrade);
		Form(Form &obj);
		virtual ~Form(void);
		Form &operator=(Form const &r);

		std::string			getName(void) const;
		bool				getSigned(void) const;
		int					getSGrade(void) const;
		int					getEGrade(void) const;

		void				signForm(void);
		void				beSigned(Bureaucrat &r);

		class GradeTooHighException : public std::exception
		{
			public:
				
				GradeTooHighException(void);
				GradeTooHighException(GradeTooHighException const &obj);
				virtual ~GradeTooHighException(void) throw();
				GradeTooHighException &operator=(GradeTooHighException const &r);
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				
				GradeTooLowException(void);
				GradeTooLowException(GradeTooLowException const &obj);
				virtual ~GradeTooLowException(void) throw();
				GradeTooLowException &operator=(GradeTooLowException const &r);
				virtual const char* what() const throw();
			
		};

	private:

		std::string	const	_name;
		bool				_signed;
		int	const			_sgrade;
		int	const			_egrade;


}; 

std::ostream	&operator<<(std::ostream &o, Form const &r); 

#endif