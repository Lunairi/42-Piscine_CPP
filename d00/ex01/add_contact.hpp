/* ************************************************************************** */
/*                                                                            */
/*    add_contact.hpp          _             _            :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef ADD_CONTACT_H
# define ADD_CONTACT_H

#include <string>

class	Info {

	public: 

		Info(void); 
		~Info(void);

		void		add_info(std::string, int i);
		std::string	get_info(int i);

	private:
		std::string _firstname;
		std::string _lastname;
		std::string _nickname;
		std::string _login;
		std::string _address;
		std::string _email;
		std::string _phone;
		std::string _birthday;
		std::string _meal;
		std::string _panties;
		std::string _secret;
		std::string _moment;
		std::string _murder;
		std::string _wtf;
		std::string _tired;
		std::string _traps;
		std::string _last;
}; 

#endif