/* ************************************************************************** */
/*                                                                            */
/*    iter.cpp               _             _              :::      ::::::::   */
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
#include <iomanip>
#include <sstream>

template <typename T>
void	print_array(T &data)
{
	std::cout << data << std::endl;
}

template <typename T>
void	iter(T *addr, size_t length, void (*func)(T &))
{
	size_t i = -1;

	while (++i < length)
		(*func)(addr[i]);
}

int main( void )
{

	std::string	test[] = 
	{
		"A", "BC", "DEF", "GHIJ", "KLMNO", "PQRSTU", "VWXYZ"
	};

	char	test2[] = 
	{
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'
	};

	int 	test3[] =
	{
		1, 12, 123, 1234, 12345, 123456, 1234567, 12345678, 123456789, 1234567890
	};

	double 	test4[] =
	{
		1.00, 1.20, 12.30, 12.34, 123.45, 1234.56, 12345.67, 123456.78, 1234567.89, 12345678.90
	};

	std::cout << "Testing Iter, printing an array of strings:" << std::endl;
	iter<std::string>(test, 7, &print_array<std::string>);

	std::cout << std::endl << "Testing Iter, printing an array of char:" << std::endl;
	iter<char>(test2, 13, &print_array<char>);

	std::cout << std::endl << "Testing Iter, printing an array of int:" << std::endl;
	iter<int>(test3, 10, &print_array<int>);

	std::cout << std::fixed << std::setprecision(2);
	std::cout << std::endl << "Testing Iter, printing an array of double:" << std::endl;
	iter<double>(test4, 10, &print_array<double>);

	return (0);
}