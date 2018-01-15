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

int	main()
{
	int i = 0;
	int x = 0;
	Bureaucrat test("Arta", 1);
	std::cout << "** Created Bureaucrat Arta, will demonstrate << overload at end of program **" << std::endl <<
		std::endl << "Demonstrating error handling, 10x loop of too high and too low" << std::endl << std::endl;
	while(i++ < 10)
	{
		try
		{
			if (i % 2 == 0)
				x = 0;
			else
				x = 151;
			Bureaucrat test2("Error Testing", x);
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl << "** Creating new Bureaucrat Selkie starting grade 8, will increase grade until its too high **" << 
		std::endl << std::endl;
	try
	{
		Bureaucrat test3("Selkie", 8);
		std::cout << test3;
		i = 0;
		while (i++ < 10)
		{
			std::cout << "* Incremented " << test3.getName() << " grade. Old grade: [" << test3.getGrade() << "]. New Grade: [";
			test3 += 1;
			std::cout << test3.getGrade() << "] *" << std::endl;
		}
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << "] *" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << "] *" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "] *" << std::endl;
	}

	std::cout << std::endl << "** Creating new Bureaucrat Aoi starting grade 130, will decrease grade until its too low **" << 
		std::endl << std::endl;
	try
	{
		Bureaucrat test4("Aoi", 130);
		std::cout << test4;
		i = 0;
		x = 0;
		while (i++ < 10)
		{
			if (i % 2 == 0)
				x = 2;
			else
				x =  3;
			std::cout << "* Incremented " << test4.getName() << " grade. Old grade: [" << test4.getGrade() << "]. New Grade: [";
			test4 -= x;
			std::cout << test4.getGrade() << "] *" << std::endl;
		}
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << "] *" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << "] *" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "] *" << std::endl;
	}

	std::cout << std::endl << "** End demonstration, now displaying << operator from Arta who was made at the start **" <<
		std::endl << test;
	return (0);
}