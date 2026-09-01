#include <stdio.h>
#include <ncurses.h>
#include <math.h>

#include "../include/map.h"
#include "../include/player.h"
#include "../include/raycasting.h"

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

	// Testing whole frame rendering
	drawFrame(&player, &map);

	int ch;
	while ((ch = getch()) != 'q')
	{
		if (ch == 'w')
		{
			player.x += cos(player.angle);
			player.y += sin(player.angle);
			drawFrame(&player, &map);
		}
		else if (ch == 's')
		{
			player.x -= cos(player.angle);
			player.y -= sin(player.angle);

			drawFrame(&player, &map);
		}
		else if (ch == 'a')
		{
			player.angle += 0.5f;
			drawFrame(&player, &map);
		}
		else if (ch == 'd')
		{
			player.angle -= 0.5f;
			drawFrame(&player, &map);
		}
	}

	endwin();
	return 1;
}
