#include "../include/map.h"

void initMap(Map *m, int nsizex, int nsizey)
{
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
