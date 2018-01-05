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
#include <string>
#include "add_contact.hpp"
#include "contact.hpp"

void		display_info(Contact *instance, int i)
{
	std::cout << "First Name: " << instance->detail[i].get_info(0) << std::endl;
	std::cout << "Last Name: " << instance->detail[i].get_info(1) << std::endl;
	std::cout << "Nickname: " << instance->detail[i].get_info(2) << std::endl;
	std::cout << "Login: " << instance->detail[i].get_info(3) << std::endl;
	std::cout << "Postal Address: " << instance->detail[i].get_info(4) << std::endl;
	std::cout << "Email Address: " << instance->detail[i].get_info(5) << std::endl;
	std::cout << "Phone Number: " << instance->detail[i].get_info(6) << std::endl;
	std::cout << "Birthdate: " << instance->detail[i].get_info(7) << std::endl;
	std::cout << "Favorite Meal: " << instance->detail[i].get_info(8) << std::endl;
	std::cout << "Underwear Color: " << instance->detail[i].get_info(9) << std::endl;
	std::cout << "Darkest Secret: " << instance->detail[i].get_info(10) << std::endl;
	std::cout << "Embarassing Moment In Life: " << instance->detail[i].get_info(11) << std::endl;
	std::cout << "User Is A Murderer: " << instance->detail[i].get_info(12) << std::endl;
	std::cout << "User Is A Pedophile: " << instance->detail[i].get_info(13) << std::endl;
	std::cout << "User Hates Me: " << instance->detail[i].get_info(14) << std::endl;
	std::cout << "User Thinks Traps Are Not Gay!" << std::endl;
	std::cout << "And User Definitely Answered Not Gay! " << std::endl;
}

void		check_search(Contact *instance, std::string response)
{
	if (response == "1" && (instance->detail[0].get_info(0) != ""))
		display_info(instance, 0);
	else if (response == "2" && (instance->detail[1].get_info(0) != ""))
		display_info(instance, 1);
	else if (response == "3" && (instance->detail[2].get_info(0) != ""))
		display_info(instance, 2);
	else if (response == "4" && (instance->detail[3].get_info(0) != ""))
		display_info(instance, 3);
	else if (response == "5" && (instance->detail[4].get_info(0) != ""))
		display_info(instance, 4);
	else if (response == "6" && (instance->detail[5].get_info(0) != ""))
		display_info(instance, 5);
	else if (response == "7" && (instance->detail[6].get_info(0) != ""))
		display_info(instance, 6);
	else if (response == "8" && (instance->detail[7].get_info(0) != ""))
		display_info(instance, 7);
	else
		std::cout << "Sorry, that index number is invalid." << std::endl;
}


std::string	check_length(Contact *instance, int i, int x)
{
	std::string input = instance->detail[i].get_info(x);
	int a = input.length();

	if (a > 10)
	{
		input.erase(9, a);
		std::cout << input;
		return (".");
	}
	while (a++ < 10)
		std::cout << " ";
	return (input);
}

int			search_contact(Contact *instance, int *total)
{
	int i = 0;
	std::string output;
	std::string response;

	if (*total == 0)
	{
		std::cout << "Sorry, there are no contacts here. You need friends :(" << std::endl;
		return (0);
	}
		std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	while (i < *total)
	{
		std::cout << "|         " << (i + 1) << "|";
		output = check_length(instance, i, 0);
		std::cout << output << "|";
		output = check_length(instance, i, 1);
		std::cout << output << "|";
		output = check_length(instance, i, 2);
		std::cout << output << "|" << std::endl;
		i++;
	}
	std::cout << std::endl;
	std::cout << "Which contact would you like to look? Please enter their index number." << std::endl;
	std::cout << "< ";
	std::getline(std::cin, response);
	check_search(instance, response);
	return (0);
}

int			add_contact(Contact *instance, int *total)
{
	int i = 0;
	std::string response = " ";

	if (*total == 8)
	{
		std::cout << "Sorry you have too many contacts, you cannot add more." << std::endl;
		return (0);
	}
	std::cout << "Please enter the following details for contact:" << std::endl;
	std::cout << "> First Name: ";
	std::getline(std::cin, response);
	instance->detail[*total].add_info(response, i++);
	std::cout << "> Last Name: ";
	std::getline(std::cin, response);
	instance->detail[*total].add_info(response, i++);
	std::cout << "> Nickname: ";
	std::getline(std::cin, response);
	instance->detail[*total].add_info(response, i++);
	std::cout << "> Login: ";
	std::getline(std::cin, response);
	instance->detail[*total].add_info(response, i++);
	std::cout << "> Postal Address: ";
	std::getline(std::cin, response);
	instance->detail[*total].add_info(response, i++);
	std::cout << "> Email Address: ";
	std::getline(std::cin, response);
	instance->detail[*total].add_info(response, i++);
	std::cout << "> Phone Number: ";
	std::getline(std::cin, response);
	instance->detail[*total].add_info(response, i++);
	std::cout << "> Birthdate: ";
	std::getline(std::cin, response);
	instance->detail[*total].add_info(response, i++);
	std::cout << "> Favorite Meal: ";
	std::getline(std::cin, response);
	instance->detail[*total].add_info(response, i++);
	std::cout << "> Underwear Color: ";
	std::getline(std::cin, response);
	instance->detail[*total].add_info(response, i++);
	std::cout << "> Darkest Secret: ";
	std::getline(std::cin, response);
	instance->detail[*total].add_info(response, i++);
	std::cout << "> Embarassing Moment In Life: ";
	std::getline(std::cin, response);
	instance->detail[*total].add_info(response, i++);
	std::cout << "> Has the contact ever murdered someone?: ";
	std::getline(std::cin, response);
	instance->detail[*total].add_info(response, i++);
	std::cout << "> Has the contact ever sodomized a small child?: ";
	std::getline(std::cin, response);
	instance->detail[*total].add_info(response, i++);
	std::cout << "> Are you tired of me yet?: ";
	std::getline(std::cin, response);
	instance->detail[*total].add_info(response, i++);
	std::cout << "> Are traps gay?: ";
	std::getline(std::cin, response);
	instance->detail[*total].add_info(response, i++);
	std::cout << "> I hope you answered no for that last question...: ";
	std::getline(std::cin, response);
	instance->detail[*total].add_info(response, i++);
	std::cout << " * * * " << std::endl;
	std::cout << "You've successfully added " << instance->detail[*total].get_info(0)
				<< " " << instance->detail[*total].get_info(1) << std::endl;
	std::cout << " * * * " << std::endl;
	*total = *total + 1;
	return (0);
}

int			exit_phone(void)
{
	std::string response = " ";

	std::cout << "Are you sure you want to exit? Nothing will be saved." << std::endl;
	std::cout << "Please enter YES to exit program, all other input will not quit." << std::endl;
	std::cout << "> ";
	std::getline(std::cin, response);
	if (response.compare("YES") == 0)
	{
		std::cout << "Goodbye forever :(" << std::endl;
		return (1);
	}
	return (0);
}

int			check_commands(std::string input, Contact *instance, int *total)
{
	if (input.compare("EXIT") == 0)
		return (exit_phone());
	else if (input.compare("ADD") == 0)
		return (add_contact(instance, total));
	else if (input.compare("SEARCH") == 0)
		return (search_contact(instance, total));
	return (0);
}

int			main(void)
{
	int i = 1;
	int total = 0;
	std::string input = " ";
	Contact *instance = new Contact();

	while (i)
	{
		std::cout << "What would you like to do?" << std::endl;
		std::cout << "Commands: ADD - SEARCH - EXIT" << std::endl;
		std::cout << "> ";
		std::getline(std::cin, input);
		if (check_commands(input, instance, &total))
			return (0);
	}
	return (0);
}