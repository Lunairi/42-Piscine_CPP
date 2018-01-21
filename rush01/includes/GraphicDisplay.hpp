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

		GraphicDisplay(std::vector<IMonitorModule*> const modules, sf::RenderWindow	&window);
		virtual ~GraphicDisplay(void);
		
		void		renderOutput(void);
		void		refreshOutput(void);

		void		graphCPU(int i);
		void		drawPony(int i);

	private:

		GraphicDisplay(void);
		GraphicDisplay(GraphicDisplay const &obj);
		GraphicDisplay	&operator=(GraphicDisplay const &r);

		std::vector<IMonitorModule*>	_modules;

		sf::RenderWindow				&_window;

		sf::Font						_arial;
		sf::Font						_trebuchet;
		sf::Font						_courier;

		sf::Color						_grey;
		sf::Color						_lightgrey;
		sf::Color						_slateblue;
		sf::Color						_azure;
		sf::Color						_lightblue;

		int								_size;
		int								_pony;
};

#endif