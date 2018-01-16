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
	Data	*data = new Data;;
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
	Serial		*serial;
	Data 		*data = new Data;

	serial = reinterpret_cast<Serial*>(raw);
	data->s1 = static_cast<std::string>(serial->s1);
	data->n = static_cast<int>(serial->n);
	data->s2 = static_cast<std::string>(serial->s2);
	return (data);
}

int	main()
{
	void	*serial;
	Data	*deserial;

	srand(time(0));
	serial = serialize();
	deserial = deserialize(serial);
	std::cout << deserial->s1 << std::endl << deserial->n << std::endl << deserial->s2 << std::endl;

	delete deserial;

	return (0);
}