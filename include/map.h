#ifndef MAP_H
#define MAP_H

#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int *layout;
	int sizex;
	int sizey;
} Map;

static inline void initMap(Map *m, int nsizex, int nsizey)
{
	m->sizex = nsizex;
	m->sizey = nsizey;

	m->layout = (int *)malloc(nsizex * nsizey * sizeof(int));

	if (m->layout == NULL)
	{
		printf("Unable to allocate memory.");
		return;
	}

	for (int i = 0; i < nsizey; i++)
	{
		for (int j = 0; j < nsizex; j++)
		{
			if (i == 0 || j == 0 || i == nsizey - 1 || j == nsizex - 1)
			{
				m->layout[i*nsizex+j] = 1;
			}
			else
			{
				m->layout[i*nsizex+j] = 0;
			}
		}
	}

	return;
}

static inline void setMapSizeX(Map *m, int nsizex) {
	m->sizex = nsizex;
	return;
}

static inline void setMapSizeY(Map *m, int nsizey) {
	m->sizey = nsizey;
	return;
}

static inline int getMapSizeX(Map *m) {
	return m->sizex;
}

static inline int getMapSizeY(Map *m) {
	return m->sizey;
}

#endif
