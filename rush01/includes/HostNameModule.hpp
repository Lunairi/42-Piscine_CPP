/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostNameModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 23:39:19 by mikim             #+#    #+#             */
/*   Updated: 2018/01/13 22:48:35 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTNAMEMODULE_HPP
# define HOSTNAMEMODULE_HPP

# include <Gkrellm.hpp>

class HostNameModule : public IMonitorModule
{
	public:

		HostNameModule(std::string const name);
		virtual ~HostNameModule(void);
		
		void				tick(void);
		std::string const	&getOutput(void) const;
		std::string const	&getName(void) const;
		
	private:

		HostNameModule(void);
		HostNameModule(HostNameModule const &obj);
		HostNameModule	&operator=(HostNameModule const &r);

		std::string			_output;
		std::string			_name;
	
};

#endif