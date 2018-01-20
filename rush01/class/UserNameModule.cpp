/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserNameModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 23:39:19 by mikim             #+#    #+#             */
/*   Updated: 2018/01/13 22:48:35 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Gkrellm.hpp>

UserNameModule::UserNameModule(std::string const name) : IMonitorModule(), _output(), _name(name)
{
	char username[255]; // 255 is max len on linux
	getlogin_r(username, 255);

	this->_output = username;
	return ;
}

UserNameModule::~UserNameModule()
{
	return ;
}

std::string const		&UserNameModule::getOutput(void) const
{
	return (this->_output);
}

std::string const		&UserNameModule::getName(void) const
{
	return (this->_name);
}

void					UserNameModule::tick(void)
{
	return ;
}
