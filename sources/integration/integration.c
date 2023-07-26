/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integration.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:00:27 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/07/07 22:10:36 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rgb_to_color(char r, char g, char b)
{
	int	rgb;

	rgb = ((((r << 8) + g) << 8) + b);
	return (rgb);
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
				cub->ray.posx = (x + 0.5);
				cub->ray.posy = (y + 0.5);
				set_dir(cub, cub->world.map[y][x]);
				return ;
			}
		}
		y++;
	}
}
