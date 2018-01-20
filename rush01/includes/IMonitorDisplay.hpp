/* ************************************************************************** */
/*                                                                            */
/*    IMonitorDisplay.hpp     _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

# include <Gkrellm.hpp>

class IMonitorDisplay
{
	public:

		IMonitorDisplay(void) {}
		virtual ~IMonitorDisplay(void) {}

		virtual void		refreshOutput(void) = 0;
		virtual void		renderOutput(void) = 0;
		
	private:

		IMonitorDisplay(IMonitorDisplay const &obj);
		IMonitorDisplay	&operator=(IMonitorDisplay const &r);
};

#endif