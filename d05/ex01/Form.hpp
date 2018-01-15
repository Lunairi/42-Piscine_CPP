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

class	Form
{

	public:

		Form(void);
		Form(std::string const name, int grade);
		Form(Form &obj);
		virtual ~Form(void);
		Form &operator=(Form const &r);

		void				operator+=(int const i);
		void				operator-=(int const i);

		std::string			getName(void) const;
		int					getGrade(void) const;

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

		std::string const	_name;
		int					_grade;


}; 

std::ostream	&operator<<(std::ostream &o, Form const &r); 

#endif