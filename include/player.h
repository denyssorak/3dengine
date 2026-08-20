#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
	float x;
	float y;
	float angle;
} Player;

// wanted to use overloading, but it doesn't work?
// void initPlayer(Player *p, float nx, float ny);

void initPlayer(Player *p, float nx, float ny, float nangle);

#endif
