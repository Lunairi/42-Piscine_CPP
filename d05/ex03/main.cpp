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

int	main()
{
	Bureaucrat	test("Arta", 1);
	Bureaucrat	test2("Lydeka", 150);
	std::cout << "** Created Bureaucrat Arta, grade 1 **" << std::endl << test << std::endl <<
		"** Created Bureaucrat Lydeka, grade 150 **" << std::endl << test2 << std::endl;

	Intern	intern;
	std::cout << "** Created new Intern, will now proceed to make forms with intern **" << std::endl << std::endl;

	Form	*ftest;

	std::cout << "** Creating Shrubbery Creation form with target Mary_Jane with Intern **" << std::endl;
	ftest = intern.makeForm("Shrubbery Creation", "Mary_Jane");

	std::cout << "** Now having Arta signed the form (should succeed), and Lydeka execute form (should fail) **" << std::endl;
	ftest->beSigned(test);
	test2.executeForm(*ftest);

	Form	*ftest2;

	std::cout << std::endl << "** Creating Robotomy Request form with target Gundam with Intern **" << std::endl;
	ftest2 = intern.makeForm("Robotomy Request", "Gundam");

	std::cout << "** Now having Arta signed the form (should succeed), and Lydeka execute form (should fail) **" << std::endl;
	ftest2->beSigned(test);
	test2.executeForm(*ftest2);

	Form	*ftest3;

	std::cout << std::endl << "** Creating Presidential Pardon form with target Obama with Intern **" << std::endl;
	ftest3 = intern.makeForm("Presidential Pardon", "Obama");

	std::cout << "** Now having Arta signed the form (should succeed), and Lydeka execute form (should fail) **" << std::endl;
	ftest3->beSigned(test);
	test2.executeForm(*ftest3);

	Form *ftest4;
	std::cout << std::endl << "** Creating Non Existent form with target Whatever with Intern, should fail **" << std::endl;
	ftest4 = intern.makeForm("Non Existent", "Whatever");

	delete ftest;
	delete ftest2;
	delete ftest3;
	delete ftest4;

	return (0);
}