#include "cub3d.h"

void	init_hooks(t_cube *cub)
{
	mlx_hook(cub->mlx.win, ON_DESTROY_WINDOW, IN_NO_EVENT, the_end, cub);
	mlx_hook(cub->mlx.win, ON_KEY_UP, IN_KEY_UP, keymapping_release_control, cub);
	mlx_hook(cub->mlx.win, ON_KEY_DOWN, IN_KEY_DOWN, keymapping_press_control, cub);
}

int	keymapping_press_control(int key, void *param)
{
	if ((key == KEY_W) || (key == KEY_A) || (key == KEY_S) || (key == KEY_D))
		moviment_engine(param, key);
	if ((key == KEY_ARR_LEFT) || (key == KEY_ARR_RIGHT))
		look_engine(param, key);
	return (0);
}

int	keymapping_release_control(int key, void *param)
{
	if (key == KEY_ESC)
		the_end(param);
	return (0);
}

int	the_end(void *param)
{
	(void) param;
	exit (0);
}