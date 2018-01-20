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

void					TerminalDisplay::renderOutput(void)
{

	// HOSTNAME
	fillSpace((char*)"-"); fillSpace((char*)"-");

	this->_text = (this->_col / 2) - 6;
	mvprintw((this->_x - 1), this->_text, " FT_GKRELLM ");
	fillSpace((char*)"-");

	this->_length = this->_modules.at(0)->getOutput().at(1).length();
	this->_text = (this->_col / 2) - (this->_length / 2);
	mvprintw((this->_x - 1), this->_text, this->_modules.at(0)->getOutput().at(1).c_str());

	fillSpace((char*)"-"); fillSpace((char*)"="); fillSpace((char*)"-");

	this->_length = this->_modules.at(0)->getName().length();
	this->_text = (this->_col / 2) - (this->_length / 2);
	mvprintw((this->_x - 1), this->_text, this->_modules.at(0)->getName().c_str());

	fillSpace((char*)"-"); fillSpace((char*)"-");

	this->_length = this->_modules.at(0)->getOutput().at(0).length();
	this->_text = (this->_col / 2) - (this->_length / 2);
	mvprintw((this->_x - 1), this->_text, this->_modules.at(0)->getOutput().at(0).c_str());
	fillSpace((char*)"="); fillSpace((char*)"-");

	// OS INFO
	this->_length = this->_modules.at(1)->getName().length();
	this->_text = (this->_col / 2) - (this->_length / 2);
	mvprintw((this->_x - 1), this->_text, this->_modules.at(1)->getName().c_str());
	fillSpace((char*)"-"); fillSpace((char*)"-");

	this->_length = this->_modules.at(1)->getOutput().at(0).length();
	this->_text = (this->_col / 2) - (this->_length / 2);
	mvprintw((this->_x - 1), this->_text, this->_modules.at(1)->getOutput().at(0).c_str());
	fillSpace((char*)"-");

	this->_length = this->_modules.at(1)->getOutput().at(1).length();
	this->_text = (this->_col / 2) - (this->_length / 2);
	mvprintw((this->_x - 1), this->_text, this->_modules.at(1)->getOutput().at(1).c_str());
	fillSpace((char*)"=");

	// Date & Time
	this->_length= this->_modules.at(2)->getName().length();
	this->_text = (this->_col / 2) - (this->_length/ 2);
	mvprintw((this->_x - 1), this->_text, this->_modules.at(2)->getName().c_str());
	fillSpace((char*)"-"); fillSpace((char*)"-");

	this->_length= this->_modules.at(2)->getOutput().at(0).length();
	this->_text = (this->_col / 2) - (this->_length/ 2);
	mvprintw((this->_x - 1), this->_text, this->_modules.at(2)->getOutput().at(0).c_str());
	fillSpace((char*)"-"); 

	this->_length= this->_modules.at(2)->getOutput().at(1).length();
	this->_text = (this->_col / 2) - (this->_length/ 2);
	mvprintw((this->_x - 1), this->_text, this->_modules.at(2)->getOutput().at(1).c_str());
	fillSpace((char*)"="); fillSpace((char*)"-");

	// CPU Info
	this->_length= this->_modules.at(3)->getName().length();
	this->_text = (this->_col / 2) - (this->_length/ 2);
	mvprintw((this->_x - 1), this->_text, this->_modules.at(3)->getName().c_str());
	fillSpace((char*)"-"); fillSpace((char*)"-");

	this->_length= this->_modules.at(3)->getOutput().at(0).length();
	this->_text = (this->_col / 2) - (this->_length/ 2);
	mvprintw((this->_x - 1), this->_text, this->_modules.at(3)->getOutput().at(0).c_str());
	fillSpace((char*)"="); fillSpace((char*)"-");
	
	// CPU Usage
	this->_length= this->_modules.at(4)->getName().length();
	this->_text = (this->_col / 2) - (this->_length/ 2);
	mvprintw((this->_x - 1), this->_text, this->_modules.at(4)->getName().c_str());
	fillSpace((char*)"-"); fillSpace((char*)"-");

	this->_length= this->_modules.at(4)->getOutput().at(0).length();
	this->_text = (this->_col / 2) - (this->_length/ 2);
	mvprintw((this->_x - 1), this->_text, this->_modules.at(4)->getOutput().at(0).c_str());
	fillSpace((char*)"-");

	this->_length= this->_modules.at(4)->getOutput().at(1).length();
	this->_text = (this->_col / 2) - (this->_length/ 2);
	mvprintw((this->_x - 1), this->_text, this->_modules.at(4)->getOutput().at(1).c_str());
	fillSpace((char*)"-");

	this->_length= this->_modules.at(4)->getOutput().at(2).length();
	this->_text = (this->_col / 2) - (this->_length/ 2);
	mvprintw((this->_x - 1), this->_text, this->_modules.at(4)->getOutput().at(2).c_str());
	fillSpace((char*)"="); fillSpace((char*)"-");

	// Ram Usage
	this->_length= this->_modules.at(5)->getName().length();
	this->_text = (this->_col / 2) - (this->_length/ 2);
	mvprintw((this->_x - 1), this->_text, this->_modules.at(5)->getName().c_str());
	fillSpace((char*)"-"); fillSpace((char*)"-");

	this->_length= this->_modules.at(5)->getOutput().at(0).length();
	this->_text = (this->_col / 2) - (this->_length/ 2);
	mvprintw((this->_x - 1), this->_text, this->_modules.at(5)->getOutput().at(0).c_str());
	fillSpace((char*)"-");

	this->_length= this->_modules.at(5)->getOutput().at(1).length();
	this->_text = (this->_col / 2) - (this->_length/ 2);
	mvprintw((this->_x - 1), this->_text, this->_modules.at(5)->getOutput().at(1).c_str());
	fillSpace((char*)"-");

	this->_length= this->_modules.at(5)->getOutput().at(2).length();
	this->_text = (this->_col / 2) - (this->_length/ 2);
	mvprintw((this->_x - 1), this->_text, this->_modules.at(5)->getOutput().at(2).c_str());
	fillSpace((char*)"-");

	this->_length= this->_modules.at(5)->getOutput().at(3).length();
	this->_text = (this->_col / 2) - (this->_length/ 2);
	mvprintw((this->_x - 1), this->_text, this->_modules.at(5)->getOutput().at(3).c_str());
	fillSpace((char*)"="); fillSpace((char*)"-");

	// Network Info
	this->_length= this->_modules.at(6)->getName().length();
	this->_text = (this->_col / 2) - (this->_length/ 2);
	mvprintw((this->_x - 1), this->_text, this->_modules.at(6)->getName().c_str());
	fillSpace((char*)"-"); fillSpace((char*)"-");

	this->_length= this->_modules.at(6)->getOutput().at(0).length();
	this->_text = (this->_col / 2) - (this->_length/ 2);
	mvprintw((this->_x - 1), this->_text, this->_modules.at(6)->getOutput().at(0).c_str());
	fillSpace((char*)"-");

	this->_length= this->_modules.at(6)->getOutput().at(1).length();
	this->_text = (this->_col / 2) - (this->_length/ 2);
	mvprintw((this->_x - 1), this->_text, this->_modules.at(6)->getOutput().at(1).c_str());
	fillSpace((char*)"=");

	box(stdscr, 42, 61);
	refresh();

	return ;
}


void					TerminalDisplay::refreshOutput(void)
{
	return ;
}
