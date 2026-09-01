#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
	float x;
	float y;
	float angle;
} Player;

static inline void initPlayer(Player *p, float nx, float ny, float nangle)
{
	p->x = nx;
	p->y = ny;
	p->angle = nangle;
	return;
}

static inline void setPlayerX(Player *p, float nx) {
	p->x = nx;
	return;
}

static inline void setPlayerY(Player *p, float ny) {
	p->y = ny;
	return;
}

static inline void setPlayerAngle(Player *p, float nangle) {
	p->angle = nangle;
	return;
}

static inline float getPlayerX(Player *p) {
	return p->x;
}

static inline float getPlayerY(Player *p) {
	return p->y;
}

static inline float getPlayerAngle(Player *p)
{
	return p->angle;
}

#endif
