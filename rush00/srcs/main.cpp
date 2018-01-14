/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 20:27:08 by lwang             #+#    #+#             */
/*   Updated: 2018/01/14 01:07:22 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Space.Invaders.hpp>

using namespace std;

void	helpMenu(int y, int x) {
	WINDOW *help = newwin(13, 25, y, x);
	box(help, 0, 0);
	mvwprintw(help, 1, 8, "CONTROLS");
	mvwprintw(help, 3, 2, "SHOOT: Spacebar");
	mvwprintw(help, 5, 2, "MOVE LEFT: <-, 4");
	mvwprintw(help, 7, 2, "MOVE RIGHT: ->, 6");
	mvwprintw(help, 9, 2, "SHOOT STRAFE LEFT: 1");
	mvwprintw(help, 11, 2, "SHOOT STRAFE RIGHT: 3");
	wrefresh(help);
	wclear(help);
	delwin(help);
}

int		space_invader(void) {

    int quit;

    int col = 0;
    int row = 0;
    getmaxyx(stdscr, col, row);

    Game *game = new Game(row - 2, col - 2);

    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    int c;
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_BLUE, COLOR_BLACK);
    refresh();

    WINDOW *menu = newwin(7, 11, (col/2 - 3), (row/2) - 5);
    while(game->checkEndgame() == 2) {
    	box(menu, 0, 0);
    	mvwprintw(menu, game->getMenu(), 2, ">");
    	if ((c = getch()) != ERR) {
			if (c == ' ' || c == KEY_UP || c == KEY_DOWN)
				system("afplay sound/boom.mp3 &");
    		if (c == ' ' && game->getMenu() == 3)
    			helpMenu((col/2) - 3, (row/2) + 7);
    		else {
    			mvwprintw(menu, game->getMenu(), 2, " ");
				game->menuInput(c);
           	}
    	}
    	mvwprintw(menu, 1, 4, "START");
    	mvwprintw(menu, 3, 4, "HELP");
    	mvwprintw(menu, 5, 4, "QUIT");
    	wrefresh(menu);
    }
    clear();
    delwin(menu);

	system("afplay sound/tara.mp3 &");
	system("afplay sound/bgm.mp3 &");

	Timer	timer(clock());
	int		curr_time = timer.checkTime(clock());
	int		y, x, cnt = 0;

    while(game->checkEndgame() == 1) {
		if (cnt % 11500 == 0) {
			if ((y = col - rand()%col) >= (col - 1))
				y = y - 3;
			if ((x = row - rand()%row) >= (row - 1))
				x = x - 3;
			mvprintw(y, x, "*");
		}
		if (cnt % 8000 == 0) {
			for (int i = 1; i< 100; i++) {
				if ((y = col - rand()%col) >= (col - 1))
					y = y - 3;
				if ((x = row - rand()%row) >= (row - 1))
					x = x - 3;
				mvprintw(y, x, " ");
			}
		}
        mvprintw(0, 0, "[SCORE  %d]", game->getScore());
        mvprintw(col - 1, 0, "[LIVES %d | LEVEL %d | TIME %d | BULLETS (%d/%d)]",
		game->getLife(), game->getLevel(), timer.getSec(clock()), game->bulletCount(), game->maxBulletCount());
        if ((c = getch()) != ERR)
            game->getInput(c);
        if (cnt % 5000 == 0)
            game->moveBullets();
        if (cnt % 6500 == 0)
            game->moveEnemyBullets();
        if (cnt % 15000 == 0)
        	game->moveEnemies();
        if (cnt % 11500 == 0)
            game->enemyBullet();
		curr_time = timer.checkTime(clock());
		cnt++;
		if (cnt > 100000000) cnt = 0;
    }

	system("killall afplay");
	system("afplay sound/gameover.mp3 &");

    WINDOW *end = newwin(7, 16, (col/2 - 3), (row/2) - 8);
    while (!game->checkEndgame()) {
    	box(end, 0, 0);
		mvwprintw(end, 1, 2, "GAMEOVER");
		mvwprintw(end, 3, 2, "SCORE: %d", game->getScore());
		mvwprintw(end, 5, 2, "LEVEL: %d", game->getLevel());
		wrefresh(end);
		if ((c = getch()) == ' ')
		{
			game->setEndgame(-2);
			delwin(end);
			clear();
		}
    }
    quit = game->checkEndgame();
    endwin();
    delete game;

    if (quit != -1)
    	return (1);
    return (0);
}

int		main() {
	srand(time(NULL));

	initscr();//creates std screen
	cbreak();//enter raw modal
	noecho();
	curs_set(0);
	while (1) {
		if (!space_invader())
		{
			clear();
			return (0);
		};
	}
}
