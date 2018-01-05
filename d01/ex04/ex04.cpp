/* ************************************************************************** */
/*                                                                            */
/*    ex04.cpp               _             _              :::      ::::::::   */
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

int	main() 
{
	std::string		hi = "HI THIS IS BRAIN";
	std::string 	*ptr = &hi;
	std::string		&ref = hi;

	std::cout << "This is display with pointer:" << std::endl << *ptr << std::endl;

	std::cout << std::endl << "This is display with reference:" << std::endl << ref << std::endl;

	return (0);
}