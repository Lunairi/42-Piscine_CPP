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
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int	main()
{

	Bureaucrat  Arta("Arta Rose", 20);
	Bureaucrat  Lydeka("Lydeka White", 100);

	std::cout << "** Created Bureaucrat Arta, grade 1 **" << std::endl << Arta << std::endl <<
		"** Created Bureaucrat Lydeka, grade 100 **" << std::endl << Lydeka << std::endl;

	Intern	whocares;
	OfficeBlock ob;
	std::cout << "** Created new Intern and new OfficeBlock **" << std::endl
		<< "** Setting Signer (Arta), and Executor (Lydeka) **" << std::endl;

	ob.setSigner(Arta);
	ob.setExecutor(Lydeka);

	try
	{
		std::cout << std::endl << "** DoBureaucracy on Shrubbery Creation target Bushes, no interns present, should catch error" << std::endl;
		ob.doBureaucracy("Shrubbery Creation", "Bushes");
	}
	catch (OfficeBlock::NoInternException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::NoSignerException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::NoExecuterException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::SignerLowGradeException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::ExecuterLowGradeException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	ob.setIntern(whocares);
	std::cout << std::endl << "** Setting Intern **" << std::endl;
	try
	{
		std::cout << std::endl << "** DoBureaucracy on Shrubbery Creation target Bushes, no interns present, should catch error" << std::endl;
		ob.doBureaucracy("Shrubbery Creation", "Bushes");
	}
	catch (OfficeBlock::NoInternException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::NoSignerException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::NoExecuterException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::SignerLowGradeException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (OfficeBlock::ExecuterLowGradeException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	return (0);
}