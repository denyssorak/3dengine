#include <stdio.h>
#include <ncurses.h>

#include "../include/map.h"

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

/*
	attron(COLOR_PAIR(1));
	printw("TESTING NCURSES");
	attroff(COLOR_PAIR(1));
*/

	Map map;
	initMap(&map, MAP_SIZEX, MAP_SIZEY);

	for (int i = 0; i < MAP_SIZEX * MAP_SIZEY; i++)
	{
		printw("%i", map.layout[i]);
	}

	int ch;
	while ((ch = getch()) != 'q')
	{
		
	}

	endwin();
	return 1;
}
