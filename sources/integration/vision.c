/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:15:18 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/07/06 22:54:01 by vde-vasc         ###   ########.fr       */
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
	cub->ray.planey = -0.66;
	return ;
}

static void	set_west(t_cube *cub)
{
	cub->ray.dirx = 1;
	cub->ray.diry = 0;
	cub->ray.planex = 0;
	cub->ray.planey = 0.66;
	return ;
}

void	set_dir(t_cube *cub, char pos)
{
	if (pos == 'N' || pos == 'S')
	{
		set_nouth(cub);
		if (pos == 'S')
			set_south(cub);
	}
	else if (pos == 'E' || pos == 'W')
	{
		set_east(cub);
		if (pos == 'W')
			set_west(cub);
	}
}
