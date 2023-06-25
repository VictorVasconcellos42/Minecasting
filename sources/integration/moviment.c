#include "cub3d.h"

void	moviment_engine(t_cube *cub, int key)
{
	(void) cub;
	if (key == KEY_W)
		cub->ray.posy -= 0.1;
	if (key == KEY_S)
		cub->ray.posy += 0.1;
	if (key == KEY_A)
		cub->ray.posx -= 0.1;
	if (key == KEY_D)
		cub->ray.posx += 0.1;
	printf("moviment activate (%fx%f)\n", cub->ray.posx, cub->ray.posy);
}

void	look_engine(t_cube *cub, int key)
{
	static int	dx = 1;
	static int	dy = 1;

	if (cub->ray.dirx == -1.0)
	{
		dx = -1;
		printf("dirx is -1 and dx is %d\n", dx);
	}
	if (cub->ray.dirx == 1.0)
	{
		dx = 1;
		printf("dirx is 1 and dx is %d\n", dx);
	}
	if (cub->ray.diry == -1.0)
	{
		dy = -1;
		printf("diry is -1 and dy is %d\n", dy);
	}
	if (cub->ray.diry == 1.0)
	{
		dy = 1;
		printf("diry is 1 and dy is %d\n", dy);
	}
	if (key == KEY_ARR_LEFT)
	{
		printf ("((%.2f - %.2f = %.2f), (%.2f - %.2f = %.2f))\n", cub->ray.dirx, (0.1 * dx), (cub->ray.dirx - (0.1 * dx)), cub->ray.diry, (0.1 * dy), (cub->ray.diry - (0.1 * dy)));
		cub->ray.dirx -= (0.1 * dx);
		cub->ray.diry -= (0.1 * dy);
	}
	if (key == KEY_ARR_RIGHT)
	{
		printf ("((%.2f + %.2f = %.2f), (%.2f - %.2f = %.2f))\n", cub->ray.dirx, (0.1 * dx), (cub->ray.dirx + (0.1 * dx)), cub->ray.diry, (0.1 * dy), (cub->ray.diry - (0.1 * dy)));
		cub->ray.dirx += (0.1 * dx);
		cub->ray.diry -= (0.1 * dy);
	}
}