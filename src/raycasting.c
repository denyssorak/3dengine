#include <math.h>
#include <ncurses.h>

#include "../include/raycasting.h"

#define FOV 75
#define ANG FOV * 3.14f / 180
#define K 160.0f

static float castRay(float posx, float posy, Map *m, float angle)
{
	float dx = 1.0 * cos(angle);
	float dy = 1.0 * sin(angle);

	float distance = 0.0f;

	float screenx = posx;
	float screeny = posy;

	int *layout = m->layout;

	while (1)
	{
		if (layout[(int)screenx + (int)screeny * m->sizex] == 1)
		{
			return distance;
		}

		screenx += dx;
		screeny += dy;
		distance += 1.0f;

		if (screenx < 0.0f || screenx >= m->sizex || screeny < 0.0f || screeny >= m->sizey)
		{
			if (m->sizex >= m->sizey)
				return m->sizex;
			return m->sizey;
		}
	}

	return -1.0f;
}

static void draw(int distance, int ceiling, int floor, int x)
{
	int y = getmaxy(stdscr);
	for (int i = 0; i < y; i++)
	{
		if (i < ceiling)
			mvprintw(i, x, ".");
		else if (i >= ceiling && i <= floor)
		{
			if (distance <= 5.0f)
			{
				mvprintw(i, x, "#");
			}
			else if (distance <= 7.0f)
			{
				mvprintw(i, x, "0");
			}
			else if (distance <= 10.0f)
			{
				mvprintw(i, x, "|");
			}
		}
		else
		{
			mvprintw(i, x, "_");
		}
	}
}

void drawFrame(Player *p, Map *m)
{
	float posx = p->x;
	float posy = p->y;

	float leftbound = p->angle + ANG/2;
	float rightbound = p->angle - ANG/2;
	
	int ymax = getmaxy(stdscr);
	int xmax = getmaxx(stdscr);

	int numrays = (int)(ANG / 0.01f);
	int wallwidth = xmax / numrays + 1;

	float distance;
	int n = 0;

	for (float i = leftbound; i >= rightbound; i -= 0.01f)
	{
		int x = (int)((float)n * xmax / numrays);

		distance = castRay(posx, posy, m, i);
		// printf("%f", distance);

		int ceiling = (ymax - K / distance) / 2;
		int floor = (ymax + K / distance) / 2;
		for (int j = x; j < x + wallwidth && j < xmax; j++)
		{
			draw(distance, ceiling, floor, j);
		}
		n++;
	}
	return;
}
