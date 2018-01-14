/* ************************************************************************** */
/*                                                                            */
/*    Game.class.cpp         _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#include <Space.Invaders.hpp>

Game::Game(int x, int y) : _mapx(x), _mapy(y), _endgame(2), _menu(1) {
	this->_eCount = 8;
	this->_eBullet = 8;
	this->_eElite = 0;
	this->_ammoPouch = 14;

	this->_bullet = new Bullet[this->_ammoPouch];
	this->_ebullet = new Bullet[this->_eBullet];
	this->_enemy = new Alien[this->_eCount];

	this->_elite = new Elite[this->_eElite];
	this->_elitebullet = new Bullet[this->_eElite * 3];

	this->_score = 0;
	this->_bspd = 34;
	this->_death = 0;
	this->_level = 0;

	spawnEnemy();
	spawnPlayer();
	this->_player.setLife(5);
}

Game::Game(Game &obj) { 
	*this = obj;
}

Game::~Game(void) {
	delete [] this->_bullet;
	delete [] this->_ebullet;
	delete [] this->_enemy;
	if (this->_eElite > 0)
		delete [] this->_elite;
}

Game &Game::operator=(Game const &r) {
	this->_input = r._input;
	for (int i = 0; i < 10; i++) {
		this->_enemy[i] = r._enemy[i];
	}
	this->_player = r._player;
	this->_endgame = r._endgame;
	return (*this);
}

int			Game::checkEndgame(void) {
	return (this->_endgame);
}

void		Game::spawnEnemy(void) {
	clear();

	system("afplay sound/respawn.mp3 &");
	if (this->_level % 3 == 0)
	{
		system("afplay sound/respawn2.mp3 &");
		this->_player.setLife(this->_player.checkLife() + 1);
		delete [] this->_elite;
		this->_eElite = (this->_level / 3);
		this->_elite = new Elite[this->_eElite];
		this->_elitebullet = new Bullet[this->_eElite * 3];
		for (int i = 0; i < this->_eElite; i++) {
			_elite[i].setPos(2 + (rand() % _mapx + 3), 1 + (rand() % 3 + 1));
			_elite[i].setLife(25);
		}
	}
	else
		this->_eElite = 0;

	delete [] this->_ebullet;
	delete [] this->_enemy;
	delete [] this->_bullet;

	this->_eCount = 10 + (this->_level * 2);
	this->_eBullet = 10 + (this->_level * 2);
	this->_ammoPouch = 16 + (this->_level * 1);

	this->_ebullet = new Bullet[this->_eBullet];
	this->_enemy = new Alien[this->_eCount];
	this->_bullet = new Bullet[this->_ammoPouch];

	this->_level++;
	if (this->_bspd > 4)
		this->_bspd -= 4;
	for (int i = 0; i < this->_eCount; i++) {
		_enemy[i].setPos(2 + (rand() % _mapx + 3), 1 + (rand() % 3 + 1));
		_enemy[i].setLife(1);
	}
}

void		Game::clearMove(void) {
	for (int i = 0; i < this->_eCount; i++){
			mvprintw(_enemy[i].getY(), _enemy[i].getX(), " ");
	}
	if (this->_eElite > 0) {
		for (int i = 0; i < this->_eElite; i++){
			_elite[i].clearElite();
		}
	}
}

void		Game::moveEnemies(void) {
	_death = 0;

	clearMove();
	for (int i = 0; i < this->_eCount; i++){
		if (_enemy[i].checkLife()) {
			if(_enemy[i].movement(_mapy, _mapx)) {
				if(_player.loseLife())
					_endgame = 0;
			}
			attron(COLOR_PAIR(2));
			mvprintw(_enemy[i].getY(), _enemy[i].getX(), "@");
			attroff(COLOR_PAIR(2));
		}
		if (!_enemy[i].checkLife())
			_death++;
    }
    if (_eElite > 0) {
		for (int i = 0; i < _eElite; i++){
			if (_elite[i].checkLife()) {
				if(_elite[i].moveElite(_mapy, _mapx)) {
					if(_player.loseLife())
						_endgame = 0;
				}
				_elite[i].drawElite();
			}
			if (!_elite[i].checkLife())
				_death++;
		}
	}
    if (_death == (_eCount + _eElite))
    	spawnEnemy();
    drawPlayer();
}

void		Game::spawnPlayer(void) {
	_player = Player(25, _mapy - 1);
	drawPlayer();
}

void		Game::drawPlayer(void) {
	attron(COLOR_PAIR(1));
	mvaddch(_player.getY(), _player.getX(), '^');
	mvaddch(_player.getY() + 1, _player.getX() + 1, '^');
	mvaddch(_player.getY() + 1, _player.getX() - 1, '^');
	attroff(COLOR_PAIR(1));
	drawEnemy();
	box(stdscr, 0, 0);
	refresh();
}

void		Game::drawEnemy(void) {
	for (int i = 0; i < this->_eCount; i++){
		if (_enemy[i].checkLife()) {
			attron(COLOR_PAIR(2));
			mvprintw(_enemy[i].getY(), _enemy[i].getX(), "@");
			attroff(COLOR_PAIR(2));
		}
    }
    if (_eElite > 0) {
		for (int i = 0; i < _eElite; i++){
			if (_elite[i].checkLife())
				_elite[i].drawElite();
		}
	}
}

void		Game::getInput(int c) {
	int a = 0;

	if (c == 27) {
		setEndgame(0);
	}
	if (c == ' ')
		playerBullet();
	if (c == KEY_RIGHT || c == KEY_LEFT || c == '6' || c == '4'
		|| c == '1' || c == '3') {
		mvaddch(_player.getY(), _player.getX(), ' ');
		mvaddch(_player.getY() + 1, _player.getX() + 1, ' ');
		mvaddch(_player.getY() + 1, _player.getX() - 1, ' ');
	}
	if ((c == KEY_RIGHT || c == '6') && _player.getX() < _mapx)
		_player.moveRight();
	if ((c == KEY_LEFT || c == '4' ) && _player.getX() > 1)
		_player.moveLeft();
	if ((c == '3') && _player.getX() < _mapx)
	{
		playerBullet();
		_player.moveRight();
	}
	if ((c == '1') && _player.getX() > 2)
	{
		playerBullet();
		_player.moveLeft();
	}
	drawPlayer();
}

int		Game::_checkHit(int x, int y) {
	for (int i = 0; i < this->_eCount; i++){
		if (_enemy[i].checkLife() && _enemy[i].isHit(x, y)) {
			_score = _score + 1;
			return (1);
		}
	}
	if (this->_eElite > 0) {
		for (int i = 0; i < this->_eElite; i++){
			if (_elite[i].checkLife() && _elite[i].isEHit(x, y)) {
				_score = _score + 1;
				return (1);
			}
		}
	}
	return (0);
}

int		Game::_checkPHit(int x, int y) {
	if (_player.isHit(x, y)) {
		system("afplay sound/death.mp3 &");
		if(_player.bulletHit()) {
			_endgame = 0;
		}
		return (1);
	}
	return (0);
}

void		Game::moveBullets(void) {
	for (int i = 0; i < this->_ammoPouch; i++) {
		if (this->_bullet[i].checkLife()) {
			this->_bullet[i].clearBullet();
			this->_bullet[i].moveUp();
			this->_bullet[i].shootBullet();
			if (this->_bullet[i].getY() == 1) {
				this->_bullet[i].setLife(0);
				this->_bullet[i].clearBullet();
			}
			if (_checkHit(this->_bullet[i].getX(), this->_bullet[i].getY())) {
				system("afplay sound/hit.mp3 &");
				this->_bullet[i].setLife(0);
				this->_bullet[i].clearBullet();
			}
		}
	}
}

void		Game::moveEnemyBullets(void) {
	for (int i = 0; i < this->_eBullet; i++) {
		if (this->_ebullet[i].checkLife()) {
			this->_ebullet[i].clearBullet();
			this->_ebullet[i].moveDown();
			this->_ebullet[i].shootEBullet();
			if (this->_ebullet[i].getY() >= (_mapy - 1)) {
				this->_ebullet[i].setLife(0);
				this->_ebullet[i].clearBullet();
			}
			if (_checkPHit(this->_ebullet[i].getX(), this->_ebullet[i].getY())) {
				this->_ebullet[i].setLife(0);
				this->_ebullet[i].clearBullet();
			}
		}
	}	
	if (this->_eElite > 0) {
		for (int i = 0; i < (_eElite * 3); i++) {
			if (this->_elitebullet[i].checkLife()) {
				this->_elitebullet[i].clearBullet();
				this->_elitebullet[i].eliteDown(i);
				this->_elitebullet[i].eliteShot();
				if (this->_elitebullet[i].getY() >= (_mapy - 1)) {
					this->_elitebullet[i].setLife(0);
					this->_elitebullet[i].clearBullet();
				}
				if (_checkPHit(this->_elitebullet[i].getX(), this->_elitebullet[i].getY())) {
					this->_elitebullet[i].setLife(0);
					this->_elitebullet[i].clearBullet();
				}
			}
		}
	}
	box(stdscr, 0, 0);
}

int			Game::bulletCount(void) {
	int x = 0;
	for (int i = 0; i < this->_ammoPouch; i++) {
		if (!this->_bullet[i].checkLife())
			x++;
	}
	return (x);
}

int			Game::maxBulletCount(void) {
	return (this->_ammoPouch);
}

void		Game::playerBullet(void) {
	static int	empty = 0;

	for (int i = 0; i < this->_ammoPouch; i++) {
		if (!this->_bullet[i].checkLife()) {
			system("afplay sound/hit2.mp3 &");
			empty = 0;
			this->_bullet[i].setInfo(_player.getX(), _player.getY(), 1);
			return;
		}
	}
	if (empty < 5) {
		system("afplay sound/empty.mp3 &");
		empty++;
	}
}

void		Game::enemyBullet(void) {
	int rd = 0;
	int x = -1;

	for (int i = 0; i < _eBullet; i++) {
		rd = rand();
		if ((rd % _bspd == 0) && !_ebullet[i].checkLife() && _enemy[i].checkLife()) {
			_ebullet[i].setInfo(_enemy[i].getX() + x, _enemy[i].getY(), 1);
			return;
		}
	}
	if (_eElite > 0)
	{
		for (int i = 0; i < _eElite; i++) {
			x++;
			if ((rd % (_bspd / 3) == 0) && !_elitebullet[i * 3].checkLife()
				&& !_elitebullet[i * 3 + 1].checkLife() 
				&& !_elitebullet[i * 3 + 2].checkLife()
				&& _elite[x].checkLife()) {
					system("afplay sound/yamato.mp3 &");
					_elitebullet[i * 3].setInfo(_elite[x].getX(), _elite[x].getY(), 1);
					_elitebullet[i * 3 + 1].setInfo(_elite[x].getX(), _elite[x].getY(), 1);
					_elitebullet[i * 3 + 2].setInfo(_elite[x].getX(), _elite[x].getY(), 1);
					return;
			}
		}
	}
}

void		Game::moveMenu(int i) {
	if (i == 1)
	{
		this->_menu += 2;
		if (this->_menu > 5)
			this->_menu = 1;
	}
	else if (i == 2)
	{
		this->_menu -= 2;
		if (this->_menu < 1)
			this->_menu = 5;
	}

}

void		Game::menuInput(int c) {
	if (_menu == 1 && c == ' ')
		_endgame = 1;
	if (_menu == 5 && c == ' ')
		_endgame = -1;
	if (c == KEY_DOWN)
		moveMenu(1);
	if (c == KEY_UP)
		moveMenu(2);
}

int			Game::getScore(void) {
	return (this->_score);
}

int			Game::getLevel(void) {
	return (this->_level);
}

int			Game::getLife(void) {
	return (this->_player.checkLife());
}

int			Game::getMenu(void) {
	return (this->_menu);
}

void		Game::setEndgame(int i) {
	this->_endgame = i;
}
