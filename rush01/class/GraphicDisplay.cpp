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

GraphicDisplay::GraphicDisplay(std::vector<IMonitorModule*> const modules, sf::RenderWindow	&window) :
		IMonitorDisplay(), _modules(modules), _window(window), _size(70)
{
	this->_arial.loadFromFile("./fonts/arial.ttf");
	this->_trebuchet.loadFromFile("./fonts/trebuc.ttf");
	this->_courier.loadFromFile("./fonts/cour.ttf");

	this->_grey.r = 64; this->_grey.g = 64; this->_grey.b = 64;
	this->_lightgrey.r = 64; this->_lightgrey.g = 64; this->_lightgrey.b = 64;
	this->_slateblue.g = 51; this->_slateblue.b = 102;
	this->_azure.r = 51; this->_azure.g = 153; this->_azure.b = 255;
	this->_lightblue.r = 153; this->_lightblue.g = 204; this->_lightblue.b = 255;

	this->_pony = -250;

	return ;
}

GraphicDisplay::~GraphicDisplay()
{
	_window.close();
	return ;
}

void					GraphicDisplay::drawPony(int i)
{
	int cc = rand();

	sf::Text	t1;
	if (cc % 5 == 0)
		t1.setFillColor(sf::Color::Black);
	else if (cc % 5 == 1)
		t1.setFillColor(sf::Color::Red);
	else if (cc % 5 == 2)
		t1.setFillColor(sf::Color::Green);
	else if (cc % 5 == 3)
		t1.setFillColor(sf::Color::Cyan);
	else
		t1.setFillColor(sf::Color::Yellow);
	t1.setCharacterSize(20);
	t1.setFont(this->_courier);
	t1.setStyle(sf::Text::Bold);

	t1.setString(this->_modules.at(i)->getOutput().at(0));
	t1.setPosition(this->_pony, this->_size + 10);
	this->_window.draw(t1);

	t1.setString(this->_modules.at(i)->getOutput().at(1));
	t1.setPosition(this->_pony, this->_size + 50);
	this->_window.draw(t1);

	t1.setString(this->_modules.at(i)->getOutput().at(2));
	t1.setPosition(this->_pony, this->_size + 90);
	this->_window.draw(t1);

	t1.setString(this->_modules.at(i)->getOutput().at(3));
	t1.setPosition(this->_pony, this->_size + 130);
	this->_window.draw(t1);

	t1.setString(this->_modules.at(i)->getOutput().at(4));
	t1.setPosition(this->_pony, this->_size + 170);
	this->_window.draw(t1);

	t1.setString(this->_modules.at(i)->getOutput().at(5));
	t1.setPosition(this->_pony, this->_size + 210);
	this->_window.draw(t1);

	this->_pony = this->_pony + 10;
	if (this->_pony > 600)
		this->_pony = -250;
}

void					GraphicDisplay::graphCPU(int i)
{
	sf::Text	t1;
	t1.setFillColor(sf::Color::Black);
	t1.setCharacterSize(30);
	t1.setFont(this->_courier);
	t1.setStyle(sf::Text::Bold);

	std::string con1 = this->_modules.at(i)->getOutput().at(0);
	std::string con2 = this->_modules.at(i)->getOutput().at(1);
	std::string con3 = this->_modules.at(i)->getOutput().at(2);

	con1 = con1.substr(con1.find_first_of("0123456789"), con1.find("%"));
	con2 = con2.substr(con2.find_first_of("0123456789"), con1.find("%"));
	con3 = con3.substr(con3.find_first_of("0123456789"), con1.find("%"));

	sf::RectangleShape c1(sf::Vector2f(380 * (stof(con1) / 100), 50));
	sf::RectangleShape c2(sf::Vector2f(380 * (stof(con2) / 100), 50));
	sf::RectangleShape c3(sf::Vector2f(380 * (stof(con3) / 100), 50));

	c1.setFillColor(sf::Color::Red);
	c2.setFillColor(sf::Color::Green);
	c3.setFillColor(sf::Color::Yellow);

	c1.setPosition(100, this->_size + 30);
	c2.setPosition(100, this->_size + 100);
	c3.setPosition(100, this->_size + 170);

	this->_window.draw(c1);
	this->_window.draw(c2);
	this->_window.draw(c3);

	t1.setString("User");
	t1.setPosition(20, this->_size + 30);
	this->_window.draw(t1);

	t1.setString("Syst");
	t1.setPosition(20, this->_size + 100);
	this->_window.draw(t1);

	t1.setString("Idle");
	t1.setPosition(20, this->_size + 170);
	this->_window.draw(t1);
}

void					GraphicDisplay::renderOutput(void)
{
	this->_window.clear(sf::Color::Black);

	sf::Texture text1;
	text1.loadFromFile("./img/header.png");
	text1.setSmooth(true);

	sf::Sprite r1;
	r1.setTexture(text1);

	sf::Texture text2;
	text2.loadFromFile("./img/body.png");
	text2.setSmooth(true);

	sf::Sprite r2;
	r2.setTexture(text2);

	sf::Texture text3;
	text3.loadFromFile("./img/title.png");
	text3.setSmooth(true);

	sf::Sprite r3;
	r3.setTexture(text3);

	r2.setPosition(0, 60);

	sf::FloatRect tr;

	sf::Text t1;
	t1.setString(" Ft_Gkrellm ");
	tr = t1.getLocalBounds();
	t1.setPosition(145, 0);
	t1.setCharacterSize(40);
	t1.setFont(this->_courier);
	t1.setStyle(sf::Text::Bold);
	t1.setFillColor(sf::Color::White);
	this->_window.draw(r3);
	this->_window.draw(t1);

	size_t i = 0;
	size_t x = 0;
	int	   y = 0;
	
	t1.setFont(this->_courier);
	while (i < this->_modules.size())
	{
		t1.setCharacterSize(50);
		t1.setFillColor(this->_lightblue);
		r1.setPosition(0, this->_size);
		t1.setString(this->_modules.at(i)->getName().c_str());
		tr = t1.getLocalBounds();
		t1.setOrigin(tr.left + tr.width/2.0f, 0);
		t1.setPosition(300, this->_size);
		this->_window.draw(r1);
		this->_window.draw(t1);
		this->_size = this->_size + 70;

		r2.setPosition(0, this->_size);
		this->_window.draw(r2);
		t1.setCharacterSize(35);
		y = (125 / this->_modules.at(i)->getOutput().size());
		t1.setFillColor(sf::Color::Black);
		if (this->_modules.at(i)->getName() == " CPU USAGE ")
			graphCPU(i);
		else if (this->_modules.at(i)->getName() == " MAGICAL PONY ")
			drawPony(i);
		else
		{
			while (x < (this->_modules.at(i)->getOutput().size()))
			{
				t1.setString(this->_modules.at(i)->getOutput().at(x).c_str());
				tr = t1.getLocalBounds();
				t1.setOrigin(tr.left + tr.width/2.0f, 0);
				t1.setPosition(300, this->_size + y + (x * 50));
				this->_window.draw(t1);
				x++;
			}
		}
		t1.setCharacterSize(50);
		this->_size = this->_size + 250;
		x = 0;
		i++;
	}
	this->_window.display();

	return ;
}

void					GraphicDisplay::refreshOutput(void)
{
	size_t i = 0;

	this->_size = 70;
	while (i < (this->_modules.size()))
	{
		this->_modules.at(i)->tick();
		i++;
	}
	renderOutput();
	return ;
}
