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
	char	*data = new char[20];

	char	output[] =
	{
		"0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
	};
	
	std::cout << "Serialized of Concatenated Arrays/Int Being Made: " << std::endl;
	while (++i < 8)
		data[i] = output[rand() % 62];
	i = 7;
	while (++i < 12)
		data[i] = rand() % 256 - 128;
	i = 11;
	while (++i < 20)
		data[i] = output[rand() % 62];
	data[i] = '\0';
	i = -1;
	std::cout << "Random Array 1: ";
	while (++i < 8)
		std::cout << data[i];
	std::cout << std::endl << "Random Integer: " << static_cast<int>(data[8]);
	i = 11;
	std::cout << std::endl << "Random Array 2: ";
	while (++i < 20)
		std::cout << data[i];
	std::cout << std::endl;
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
	data->n = input[8];
	i = 11;
	while (++i < 20)
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
		"Random Integer: " << deserial->n << std::endl << 
		"Random Array 2: " << deserial->s2 << std::endl;

	delete deserial;

	return (0);
}