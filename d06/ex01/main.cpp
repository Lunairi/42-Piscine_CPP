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
#include "Serialization.hpp"



void 	*serialize(void)
{
	int 	i = -1;
	char	*data = new char[18];

	char	output[] =
	{
		"0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
	};
	
	std::cout << "Serialized of Concatenated Arrays/Int Being Made: ";
	while (++i < 8)
		data[i] = output[rand() % 62];
	i = 7;
	while (++i < 10)
		data[i] = output[rand() % 10];
	i = 9;
	while (++i < 18)
		data[i] = output[rand() % 62];
	data[i] = '\0';
	std::cout << data << std::endl;
	return (reinterpret_cast<void*>(data));
}

Data 	*deserialize(void	*raw)
{
	Data 		*data = new Data;

	data->n = 0;
	char		*input = reinterpret_cast<char*>(raw);
	int i = -1;

	while (++i < 8)
		data->s1 = data->s1 + input[i];
	i = 7;
	while (++i < 10)
		data->n = data->n * 10 + input[i] - '0';
	i = 9;
	while (++i < 18)
		data->s2 = data->s2 + input[i];
	return (data);
}

int	main()
{
	void	*serial;
	Data	*deserial;

	srand(time(0));
	serial = serialize();
	std::cout << "Address of the random serialized data" << std::endl << serial << std::endl << std::endl;
	deserial = deserialize(serial);
	std::cout << "Results of deserializing the serialized data using the address" << std::endl <<
		"Random Array 1: " << deserial->s1 << std::endl << 
		"Random Integers: " << deserial->n << std::endl << 
		"Random Array 2: " << deserial->s2 << std::endl;

	delete deserial;

	return (0);
}