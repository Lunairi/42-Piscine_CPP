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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{

	Bureaucrat	test("Arta", 1);
	Bureaucrat	test2("Lydeka", 150);
	std::cout << "** Created Bureaucrat Arta, grade 1 **" << std::endl << test << std::endl <<
		"** Created Bureaucrat Lydeka, grade 150 **" << std::endl << test2 << std::endl <<
		"** Creating Shrubbery Form <Snoop_Dogg> **" << std::endl;

	ShrubberyCreationForm shrub("Snoop_Dogg");
	std::cout << shrub << std::endl << "** Executing form before signing, it will not work **" << std::endl;

	shrub.execute(test);

	std::cout << std::endl << "** Now signing the form with Arta and than executing the form **" << std::endl;
	shrub.beSigned(test);
	test.executeForm(shrub);

	try
	{
		std::cout << std::endl << "** Attempting to execute form with Lydeka which should error **" << std::endl;
		test2.executeForm(shrub);
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

	std::cout << std::endl << "** Creating Robotomy Request Form <Robot> **" << std::endl;

	RobotomyRequestForm robot("Robot");
	std::cout << robot << std::endl << "**Executing form before signing, it will not work **" << std::endl;

	robot.execute(test);

	std::cout << std::endl << "** Now signing the form with Arta and than executing the form 2x **" << std::endl;
	robot.beSigned(test);
	test.executeForm(robot);
	test.executeForm(robot);

	try
	{
		std::cout << std::endl << "** Attempting to execute form with Lydeka which should error **" << std::endl;
		test2.executeForm(robot);
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

	std::cout << std::endl << "** Creating Presidential Pardon Form <I Didn't Do It I Swear> **" << std::endl;

	PresidentialPardonForm pres("I Didn't Do It I Swear");
	std::cout << pres << std::endl << "**Executing form before signing, it will not work **" << std::endl;

	pres.execute(test);

	std::cout << std::endl << "** Now signing the form with Arta and than executing the form **" << std::endl;
	pres.beSigned(test);
	test.executeForm(pres);

	try
	{
		std::cout << std::endl << "** Attempting to execute form with Lydeka which should error **" << std::endl;
		test2.executeForm(pres);
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