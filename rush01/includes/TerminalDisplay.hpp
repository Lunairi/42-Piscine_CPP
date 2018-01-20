/* ************************************************************************** */
/*                                                                            */
/*    TerminalDisplay.hpp    _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */


#ifndef TERMINALDISPLAY_HPP
# define TERMINALDISPLAY_HPP

# include <Gkrellm.hpp>

class TerminalDisplay : public IMonitorDisplay
{
	public:

		TerminalDisplay(std::vector<IMonitorModule*> const modules);
		virtual ~TerminalDisplay(void);
		
		void		renderOutput(void);
		void		refreshOutput(void);
		void		fillSpace(char *str);
		
	private:

		TerminalDisplay(void);
		TerminalDisplay(TerminalDisplay const &obj);
		TerminalDisplay	&operator=(TerminalDisplay const &r);

		std::vector<IMonitorModule*>	_modules;

		int		_x;
		int		_y;
		int		_length;
		int		_text;
		int		_col;
		int		_row;
	
};

#endif