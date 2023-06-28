/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:15:18 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/06/28 19:48:00 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_nouth(t_cube *cub)

{
	cub->ray.dirx = 0;
	cub->ray.diry = -1;
	cub->ray.planex = 0.66;
	cub->ray.planey = 0;
	return ;
}

static void	set_south(t_cube *cub)

{
	cub->ray.dirx = 0;
	cub->ray.diry = 1;
	cub->ray.planex = -0.66;
	cub->ray.planey = 0;
	return ;
}

static void	set_east(t_cube *cub)
{
	cub->ray.dirx = -1;
	cub->ray.diry = 0;
	cub->ray.planex = 0;
	cub->ray.planey = 0.66;
	return ;
}

static void	set_west(t_cube *cub)
{
	cub->ray.dirx = 1;
	cub->ray.diry = 0;
	cub->ray.planex = 0;
	cub->ray.planey = -0.66;
	return ;
}

void	set_dir(t_cube *cub, char pos)
{
	if (pos == 'N' || pos == 'S')
	{
		cub->ray.angle = 270;
		set_nouth(cub);
		if (pos == 'S')
		{
			set_south(cub);
			cub->ray.angle = 90;
		}
	}
	else if (pos == 'E' || pos == 'W')
	{
		cub->ray.angle = 0;
		set_east(cub);
		if (pos == 'W')
		{
			cub->ray.angle = 180;
			set_west(cub);
		}
	}
	printf ("dir:%f, %f [%d°]\n", cub->ray.dirx, cub->ray.diry, cub->ray.angle);
}
