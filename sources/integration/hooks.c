/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:35:59 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/01 01:18:56 by thfirmin         ###   ########.fr       */
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
	if (key == KEY_ESC)
		the_end(param);
	return (0);
}

int	the_end(void *param)
{
	(void) param;
	exit (0);
}
