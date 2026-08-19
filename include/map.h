#ifndef MAP_H
#define MAP_H

#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int *layout;
	int sizex;
	int sizey;
} Map;

void initMap(Map *m, int nsizex, int nsizey);

#endif
