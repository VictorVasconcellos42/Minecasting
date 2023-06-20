/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intergration.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:00:27 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/06/20 18:54:08 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_dir(t_cube *cub, char pos)

{
	if (pos == 'N' || pos == 'S')
	{
		cub->ray.dirx = 0;
		cub->ray.diry = -1;
		if (pos == 'S')
			cub->ray.diry = 1;
	}
	else if (pos == 'E' || pos == 'W')
	{
		cub->ray.diry = 0;
		cub->ray.dirx = -1;
		if (pos == 'W')
			cub->ray.dirx = 1;
	}
}

static int	is_player(char pos)

{
	if (pos == 'N' || pos == 'E' || pos == 'S' || pos == 'W')
		return (TRUE);
	return (FALSE);
}

void	integration(t_cube *cub)
{
	int y;
	int x;

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
