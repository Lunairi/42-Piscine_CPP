/* ************************************************************************** */
/*                                                                            */
/*    Pony.cpp               _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#include <iostream>
#include "Pony.hpp"

Pony::Pony(std::string nick, int hoof, std::string hair, bool trained) : name(nick), legs(hoof), mane(hair), saddle(trained)
{
	std::cout << "Pony " << this->name << " has magically landed unto this world with grace and passion." << std::endl;
	return;
}

Pony::~Pony(void) 
{
	std::cout << "Pony " << this->name << " has flown off to bring happiness and fabulousness to the rest of the world." << std::endl;
	return;
}