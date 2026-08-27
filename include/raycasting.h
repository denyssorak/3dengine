#ifndef RAYCASTING_H
#define RAYCASTING_H

#include "../include/player.h"
#include "../include/map.h"

void render_frame(Player *p, Map *m);

float castray(float posx, float posy, int *layout, float angle);

#endif
