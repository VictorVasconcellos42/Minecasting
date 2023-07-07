/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:35:59 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/07 20:07:10 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_hooks(t_cube *cub)
{
	mlx_hook(cub->mlx.win, ON_DESTROY_WINDOW, IN_NO_EVENT, the_end, cub);
	mlx_hook(cub->mlx.win, ON_KEY_UP, IN_KEY_UP, keymap_release_control, cub);
	mlx_hook(cub->mlx.win, ON_KEY_DOWN, IN_KEY_DOWN, keymap_press_control, cub);
}

int	keymap_press_control(int key, void *param)
{
	t_cube	*cub;

	cub = param;
	if ((key == KEY_W) || (key == KEY_A) || (key == KEY_S) || (key == KEY_D))
		moviment_engine(cub, key);
	if ((key == KEY_ARR_LEFT) || (key == KEY_ARR_RIGHT))
		look_engine(cub, key, &cub->ray.dirx, &cub->ray.diry);
	return (0);
}

int	keymap_release_control(int key, void *param)
{
	t_cube	*cub;

	cub = param;
	if (key == KEY_ESC)
		the_end(param);
	if (key == KEY_N)
		cub->map_switch = !cub->map_switch;
	return (0);
}

int	the_end(void *param)
{
	t_cube *cub;
	(void) param;
	(void) cub;
	cub = param;
	free_text(&cub->text, &cub->mlx);
	free_mlx(&cub->mlx);
	free_map(&cub->world);
	exit (0);
}
