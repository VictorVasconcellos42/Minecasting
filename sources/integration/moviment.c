#include "cub3d.h"

void	moviment_engine(t_cube *cub, int key)
{
	(void) cub;
	if (key == KEY_W)
		cub->ray.posy -= 1;
	if (key == KEY_S)
		cub->ray.posy += 1;
	if (key == KEY_A)
		cub->ray.posx -= 1;
	if (key == KEY_D)
		cub->ray.posx += 1;
	printf("moviment activate (%fx%f)\n", cub->ray.posx, cub->ray.posy);
}

void	look_engine(t_cube *cub)
{
	(void) cub;
	ft_printf ("look activate\n");
}