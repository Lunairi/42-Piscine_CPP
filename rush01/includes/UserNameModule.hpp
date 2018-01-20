/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserNameModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 23:39:19 by mikim             #+#    #+#             */
/*   Updated: 2018/01/13 22:48:35 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERNAMEMODULE_HPP
# define USERNAMEMODULE_HPP

# include <Gkrellm.hpp>

class UserNameModule : public IMonitorModule
{
	public:

		UserNameModule(std::string const name);
		virtual ~UserNameModule(void);
		
		void				tick(void);
		std::string const	&getOutput(void) const;
		std::string const	&getName(void) const;
		
	private:

		UserNameModule(void);
		UserNameModule(UserNameModule const &obj);
		UserNameModule	&operator=(UserNameModule const &r);

		std::string			_output;
		std::string			_name;
	
};

#endif