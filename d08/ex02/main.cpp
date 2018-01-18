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
#include <random>

#include "mutantstack.hpp"

int main()
{

	std::cout << "Mutated abomination outputs:" << std::endl;
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << std::endl << "Checking output with std::list outputs:" << std::endl;
	std::list<int>	lmstack;

	lmstack.push_front(5);
	lmstack.push_front(17);
	std::cout << lmstack.front() << std::endl;
	lmstack.pop_front();
	std::cout << lmstack.size() << std::endl;
	lmstack.push_front(3);
	lmstack.push_front(5);
	lmstack.push_front(737);
	//[...]
	lmstack.push_front(0);

	MutantStack<int>::iterator lit = lmstack.begin();
	MutantStack<int>::iterator lite = lmstack.end();
	++lit;
	--lit;

	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}
	std::stack<int> ls(mstack);

	return 0;
}