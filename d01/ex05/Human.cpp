/* ************************************************************************** */
/*                                                                            */
/*    Human.cpp              _             _              :::      ::::::::   */
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
#include "Human.hpp"
#include "Brain.hpp"

Human::Human(void)
{
	return;
}

Human::~Human(void)
{
	return;
}

std::string Human::identify()
{
	return (this->refbrain.identify());
}

Brain &Human::getBrain(void)
{
	return (this->refbrain);
}