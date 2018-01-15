/* ************************************************************************** */
/*                                                                            */
/*    main.cpp               _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	int i = 0;
	int x = 0;

	Bureaucrat	test("Arta", 1);
	std::cout << "** Created Bureaucrat Arta, grade 1 **" << std::endl << test;

	Form		form("Declaration of Independence", 100, 100);
	std::cout << "** Created Form <Declaration of Independence> with sign & exec requirement of 100 **" << std::endl
		<< form << std::endl << "** Having Arta sign <Declaration of Independence> **" << std::endl;

	form.beSigned(test);
	std::cout << form << std::endl << "** Having Arta try signing it again **" << std::endl;
	form.beSigned(test);

	std::cout << std::endl << "** Attempting to create forms with 0 and 151 grade which test error catching **" << std::endl;

	while(i++ < 10)
	{
		try
		{
			if (i % 2 == 0)
				x = 0;
			else
				x = 151;
			Form form2("Error Testing", x, x);
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
	std::cout << std::endl << "** Creating new Bureaucrat Lydeka with grade 100 and new form <Mortgage Loans> with requirement of grade 50 or higher **"
		<< std::endl << std::endl;

	try
	{
		Bureaucrat test2("Lydeka", 100);
		std::cout << test2;

		Form form3("Mortgage Loans", 50, 50);
		std::cout << form3;

		form3.beSigned(test2);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}