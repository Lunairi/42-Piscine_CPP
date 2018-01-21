/* ************************************************************************** */
/*                                                                            */
/*    TerminalDisplay.cpp    _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */


#include <Gkrellm.hpp>

TerminalDisplay::TerminalDisplay(std::vector<IMonitorModule*> const modules) : IMonitorDisplay(), _modules(modules),
																				_x(1), _y(-1), _length(0), _text(0)
{

	initscr();
	cbreak();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    this->_pony = 0;

    start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_BLUE, COLOR_BLACK);

	getmaxyx(stdscr, this->_row, this->_col);

	return ;
}

TerminalDisplay::~TerminalDisplay()
{
	endwin();
	return ;
}

void					TerminalDisplay::fillSpace(char *str)
{
	while (this->_y < this->_col)
	{
		mvprintw(this->_x, this->_y, str);
		this->_y = this->_y + 1;
	}
	this->_x = this->_x + 1;
	this->_y = -1;
}

void					TerminalDisplay::drawPony(int i)
{
	int		input [] = { 1, 2, 3, 4, 5, 6 };

	int p = rand() % 6;
	size_t x = 0;
	while (x < (this->_modules.at(i)->getOutput().size()))
	{
		fillSpace((char*)"-");
		attron(COLOR_PAIR(input[p]));
		mvprintw((this->_x - 1), this->_pony, this->_modules.at(i)->getOutput().at(x).c_str());
		attroff(COLOR_PAIR(input[p]));
		x++;
	}
	this->_pony = this->_pony + 1;
	if (this->_pony > this->_col)
		this->_pony = 0;
}

void					TerminalDisplay::renderOutput(void)
{
	fillSpace((char*)"-"); fillSpace((char*)"-");

	this->_text = (this->_col / 2) - 6;
	mvprintw((this->_x - 1), this->_text, " FT_GKRELLM ");
	fillSpace((char*)"-"); fillSpace((char*)"=");

	size_t i = 0;
	size_t x = 0;

	while (i < (this->_modules.size()))
	{
		fillSpace((char*)"-");
		this->_length = this->_modules.at(i)->getName().length();
		this->_text = (this->_col / 2) - (this->_length / 2);
		mvprintw((this->_x - 1), this->_text, this->_modules.at(i)->getName().c_str());
		fillSpace((char*)"-");
		if (this->_modules.at(i)->getName() == " MAGICAL PONY ")
			drawPony(i);
		else
		{
			while (x < (this->_modules.at(i)->getOutput().size()))
			{
				fillSpace((char*)"-");
				this->_length = this->_modules.at(i)->getOutput().at(x).length();
				this->_text = (this->_col / 2) - (this->_length / 2);
				mvprintw((this->_x - 1), this->_text, this->_modules.at(i)->getOutput().at(x).c_str());
				x++;
			}
		}
		fillSpace((char*)"=");
		x = 0;
		i++;
	}

	box(stdscr, 42, 61);
	refresh();

	return ;
}

void					TerminalDisplay::refreshOutput(void)
{
	size_t i = 0;

	this->_x = 1;
	this->_y = -1;
	while (i < (this->_modules.size()))
	{
		this->_modules.at(i)->tick();
		i++;
	}
	renderOutput();
	return ;
}
