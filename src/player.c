#include "../include/player.h"

/*
void initPlayer(Player *p, float nx, float ny)
{
	p->x = nx;
	p->y = ny;
	p->angle = 0.0f;

	return;
}
*/

void initPlayer(Player *p, float nx, float ny, float nangle)
{
	p->x = nx;
	p->y = ny;
	p->angle = nangle;

	return;
}
