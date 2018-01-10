/* ************************************************************************** */
/*                                                                            */
/*    NinjaTrap.cpp           _             _              :::      ::::::::   */
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
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"

NinjaTrap::NinjaTrap(void)
{
	srand(time(0));
	ClapTrap::setStats("NNJ4-TP", 1, 60, 60, 120, 120, 60, 5, 0);
	std::cout << "NNJ4-TP Default Constructor Called: [" << this->name << "] It's time to get dirty!" << std::endl;
	return;
}

NinjaTrap::NinjaTrap(std::string name)
{
	srand(time(0));
	ClapTrap::setStats(name, 1, 60, 60, 120, 120, 60, 5, 0);
	std::cout << "NNJ4-TP Parameter Constructor Called: [" << this->name << "] It's time to get dirty!" << std::endl;
	return;
}

NinjaTrap::NinjaTrap(NinjaTrap &obj)
{
	srand(time(0));
	*this = obj;
	std::cout << "NNJ4-TP Copy Constructor Called: [" << this->name << "] Just like a Ninja I can clone!" << std::endl;
	return;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "NNJ4-TP destructor Called: [" << this->name << "] I guess I was roadkilled!" << std::endl;
	return;
}

NinjaTrap &NinjaTrap::operator=(NinjaTrap const &r) 
{
	ClapTrap::operator=(r);
	std::cout << "Assigning Operator Called: [" << this->name << "] I am nothing but a breeze!" << std::endl << std::endl;
	return (*this);
}

void	NinjaTrap::ninjaShoeBox(ClapTrap &obj)
{
	std::cout << "[" << this->name << "] Psst... I see you CL4P-TP " << obj.name << "." << std::endl;
	std::cout << "[" << this->name << "] You're probably wondering where I am, don't worry. Instead, let me tell you a joke." 
		<< obj.name << std::endl;
	std::cout << "[" << this->name << "] How many skags would Brick eat if Brick could eat skags?" << std::endl;
		std::cout << "[" << this->name << "] All of them! Hahaha, Ninja's have great humor right?" << std::endl << std::endl;
	return;
}

void	NinjaTrap::ninjaShoeBox(FragTrap &obj)
{
	std::cout << "[" << this->name << "] Psst... I see you FR4G-TP " << obj.name << "." << std::endl;
	std::cout << "[" << this->name << "] You're probably wondering where I am, don't worry. Instead, let me tell you a joke." 
		<< obj.name << std::endl;
	std::cout << "[" << this->name << "] How can you tell when Roland likes a bandit?" << std::endl;
	std::cout << "[" << this->name << "] He shoots them in the head." << std::endl;
	std::cout << "[" << this->name << "] How can you tell when Roland hates a bandit?" << std::endl;
	std::cout << "[" << this->name << "] He shoots them in the head. Hahaha I know I'm so funny!" << std::endl << std::endl;
	return;	
}

void	NinjaTrap::ninjaShoeBox(NinjaTrap &obj)
{
	std::cout << "[" << this->name << "] Psst... I see you NNJ4-TP " << obj.name << "." << std::endl;
	std::cout << "[" << this->name << "] You're probably wondering where I am, don't worry. Instead, let me tell you a joke." 
		<< obj.name << std::endl;
	std::cout << "[" << this->name << "] What is the last thing to go through bandits' mind when they meet Brick?" << std::endl;
		std::cout << "[" << this->name << "] Brick's Fist. HAHAHAH I crack myself up." << std::endl << std::endl;
	return;	
}

void	NinjaTrap::ninjaShoeBox(ScavTrap &obj)
{
	std::cout << "[" << this->name << "] Psst... I see you SC4V-TP " << obj.name << "." << std::endl;
	std::cout << "[" << this->name << "] You're probably wondering where I am, don't worry. Instead, let me tell you a joke." 
		<< obj.name << std::endl;
	std::cout << "[" << this->name << "] What never shuts up but is impossible to find?" << std::endl <<
		std::cout << "[" << this->name << "] ClapTraps! And guess what? NinjaTraps are harder to find!" << std::endl << std::endl;
	return;	
}
