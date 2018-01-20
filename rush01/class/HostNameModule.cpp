/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostNameModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 23:39:19 by mikim             #+#    #+#             */
/*   Updated: 2018/01/13 22:48:35 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Gkrellm.hpp>

HostNameModule::HostNameModule(std::string const name) : IMonitorModule(), _output(), _name(name)
{
	char hostname[255]; // 255 is max len on linux
	gethostname(hostname, 255);

	this->_output = hostname;
	return ;
}

HostNameModule::~HostNameModule()
{
	return ;
}

std::string const		&HostNameModule::getOutput(void) const
{
	return (this->_output);
}

std::string const		&HostNameModule::getName(void) const
{
	return (this->_name);
}

void					HostNameModule::tick(void)
{
	return ;
}
