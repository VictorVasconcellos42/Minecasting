/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integration.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:00:27 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/06/25 18:05:16 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rgb_to_color(char r, char g, char b)
{
	int	rgb;

	rgb = ((((r << 8) + g) << 8) + b);
	return (rgb);
}

// Find player direction
static void	set_dir(t_cube *cub, char pos)
{
	if (pos == 'N' || pos == 'S')
	{
		cub->ray.angle = 270;
		cub->ray.dirx = 0;
		cub->ray.diry = -1;
		if (pos == 'S')
		{
			cub->ray.diry = 1;
			cub->ray.angle = 90;
		}
	}
	else if (pos == 'E' || pos == 'W')
	{
		cub->ray.angle = 0;
		cub->ray.diry = 0;
		cub->ray.dirx = -1;
		if (pos == 'W')
		{
			cub->ray.angle = 180;
			cub->ray.dirx = 1;
		}
	}
	printf ("dir:%f, %f [%d°]\n", cub->ray.dirx, cub->ray.diry, cub->ray.angle);
}

static int	is_player(char pos)
{
	if (pos == 'N' || pos == 'E' || pos == 'S' || pos == 'W')
		return (TRUE);
	return (FALSE);
}

// Find player respawn in map and save your position
void	integration(t_cube *cub)
{
	int	y;
	int	x;

	y = 0;
	while (cub->world.map[y])
	{
		x = -1;
		while (cub->world.map[y][++x])
		{
			if (is_player(cub->world.map[y][x]))
			{
				cub->ray.posx = x;
				cub->ray.posy = y;
				set_dir(cub, cub->world.map[y][x]);
				return ;
			}
		}
		y++;
	}
}
