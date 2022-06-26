#include "../includes/cub3d.h"

float px, py, pdx, pdy, pa;	//player position angle

void	retate_player()
{
	
}
void	buttons(unsigned char key, int x, int y)
{
	if (key == 'a')
	{
		pa -= 0.1;
		if (pa < 0)
			pa += 2 * PI;
		pdx	= cos(pa) * 5;
		pdy = sin(pa) * 5;	
	}
	if (key == 'd')
	{
		pa += 0.1;
		if (pa >  2 * PI)
			pa -= 2 * PI;
		pdx	= cos(pa) * 5;
		pdy = sin(pa) * 5;	
	}
	if (key = 's')
	{
		px -= pdx;
		py -= pdy;
	}
	if (key = 'w')
	{
		px += pdx;
		py += pdy;
	}
	//call back the screen function to rotate player
}