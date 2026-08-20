#include <stdio.h>
#include <ncurses.h>

#include "../include/map.h"
#include "../include/player.h"

#define MAP_SIZEX 10
#define MAP_SIZEY 10

void initNcurses(void)
{
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);

	if (has_colors())
	{
		start_color();
		init_pair(1, COLOR_BLACK, COLOR_WHITE);
	}
}

int main(void)
{
	initNcurses();

	Map map;
	initMap(&map, MAP_SIZEX, MAP_SIZEY);

	Player player;
	initPlayer(&player, 5.0f, 5.0f, 0.0f);

/*	// Testing map intialization
	for (int i = 0; i < MAP_SIZEX * MAP_SIZEY; i++)
	{
		printw("%i", map.layout[i]);
	}
*/

/*	// Testing player initialization
	printw("%f\n", player.x);
	printw("%f\n", player.y);
	printw("%f\n", player.angle);
*/

	int ch;
	while ((ch = getch()) != 'q')
	{
		
	}

	endwin();
	return 1;
}
