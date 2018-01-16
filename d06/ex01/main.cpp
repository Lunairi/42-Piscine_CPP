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
	Data	*data = new Data;
	int 	i = 0;

	char	output[] =
	{
		"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
	};
	
	while (i++ < 8)
		data->s1 = data->s1 + output[rand() % 62];
	data->n = rand();
	i = 0;
	while (i++ < 8)
		data->s2 = data->s2 + output[rand() % 62];
	return (reinterpret_cast<void*>(data));
}

Data 	*deserialize(void	*raw)
{
	Data 		*data = new Data;

	data = reinterpret_cast<Data*>(raw);
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