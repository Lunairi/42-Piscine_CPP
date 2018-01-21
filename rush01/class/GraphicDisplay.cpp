/* ************************************************************************** */
/*                                                                            */
/*    GraphicDisplay.cpp     _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */


#include <Gkrellm.hpp>

GraphicDisplay::GraphicDisplay(std::vector<IMonitorModule*> const modules) : IMonitorDisplay(), _modules(modules)
{

	// this->_mlx = mlx_init();
	// this->_win = mlx_new_window(this->_mlx, 1000, 1000, (char*)"Kill me please");
	// this->_img = mlx_new_image(this->_mlx, 1000, 1000);
	// this->_pix = (int*)mlx_get_data_addr(this->_img,
	// 	&(this->_bits), &(this->_sline), &(this->_endian));

	return ;
}

GraphicDisplay::~GraphicDisplay()
{
	// endwin();
	return ;
}


void					*GraphicDisplay::getMlx(void)
{
	return (this->_mlx);
}

void					*GraphicDisplay::getWin(void)
{
	return (this->_win);
}
		

void					GraphicDisplay::fillSpace(char *str)
{
	(void)str;
	// while (this->_y < this->_col)
	// {
	// 	mvprintw(this->_x, this->_y, str);
	// 	this->_y = this->_y + 1;
	// }
	// this->_x = this->_x + 1;
	// this->_y = -1;
}

void					GraphicDisplay::renderOutput(void)
{
	// fillSpace((char*)"-"); fillSpace((char*)"-");

	// this->_text = (this->_col / 2) - 6;
	// mvprintw((this->_x - 1), this->_text, " FT_GKRELLM ");
	// fillSpace((char*)"-"); fillSpace((char*)"=");

	// size_t i = 0;
	// size_t x = 0;

	// while (i < (this->_modules.size()))
	// {
	// 	fillSpace((char*)"-");
	// 	this->_length = this->_modules.at(i)->getName().length();
	// 	this->_text = (this->_col / 2) - (this->_length / 2);
	// 	mvprintw((this->_x - 1), this->_text, this->_modules.at(i)->getName().c_str());
	// 	fillSpace((char*)"-");
	// 	while (x < (this->_modules.at(i)->getOutput().size()))
	// 	{
	// 		fillSpace((char*)"-");
	// 		this->_length = this->_modules.at(i)->getOutput().at(x).length();
	// 		this->_text = (this->_col / 2) - (this->_length / 2);
	// 		mvprintw((this->_x - 1), this->_text, this->_modules.at(i)->getOutput().at(x).c_str());
	// 		x++;
	// 	}
	// 	fillSpace((char*)"=");
	// 	x = 0;
	// 	i++;
	// }

	// box(stdscr, 42, 61);
	// refresh();

	return ;
}

void					GraphicDisplay::refreshOutput(void)
{
	// size_t i = 0;

	// this->_x = 1;
	// this->_y = -1;
	// while (i < (this->_modules.size()))
	// {
	// 	this->_modules.at(i)->tick();
	// 	i++;
	// }
	// renderOutput();
	return ;
}
