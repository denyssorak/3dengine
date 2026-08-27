#include <math.h>
#include <ncurses.h>

#include "../include/raycasting.h"

#define FOV 75
#define ANGLE FOV * 3.14 / 180
#define COEF 0.33

void render_frame(Player *p, Map *m)
{
	float posx = p->x;
	float posy = p->y;

	int *layout = m->layout;

	float leftbound = p->angle + ANGLE/2;
	float rightbound = p->angle - ANGLE/2;
	
	int x = 0;
	float dist = 0;

	for (float i = leftbound; i >= rightbound; i -= 0.1f)
	{
		dist = castray(posx, posy, layout, i);
		mvprintw(3, x, "%.3f", i);
		mvprintw(5, x, "%i", (int)dist);
		x += 7;
	}
}

float castray(float posx, float posy, int *layout, float angle)
{
	float dx = COEF * cos(angle);
	float dy = COEF * sin(angle);

	float dist = 0.0f;

	float screenx = posx;
	float screeny = posy;

	while (1)
	{
		if (layout[(int)screenx + (int)screeny * 10] == 1)
		{
			return dist;
		}
		screenx += dx;
		screeny += dy;
		dist += 1.0f;

		if (screenx >= 10.0f || screenx < 0.0f || screeny >= 10.0f || screeny < 0.0f)
		{
			return 10.0f;
		}
	}
}
