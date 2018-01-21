/* ************************************************************************** */
/*                                                                            */
/*    GraphicDisplay.hpp     _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */


#ifndef GRAPHICDISPLAY_HPP
# define GRAPHICDISPLAY_HPP

# include <Gkrellm.hpp>

class GraphicDisplay : public IMonitorDisplay
{
	public:

		GraphicDisplay(std::vector<IMonitorModule*> const modules);
		virtual ~GraphicDisplay(void);
		
		void		renderOutput(void);
		void		refreshOutput(void);
		void		fillSpace(char *str);

		void		*getMlx(void);
		void		*getWin(void);
		
	private:

		GraphicDisplay(void);
		GraphicDisplay(GraphicDisplay const &obj);
		GraphicDisplay	&operator=(GraphicDisplay const &r);

		std::vector<IMonitorModule*>	_modules;

		void		*_mlx;
		void		*_win;
		void		*_img;
		int			*_pix;
		int			_bits;
		int			_sline;
		int			_endian;
	
};

#endif