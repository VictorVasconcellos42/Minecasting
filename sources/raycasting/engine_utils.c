/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:44:13 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/05/29 20:08:30 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	set_color(t_cube *cub)

{
	int	color;

	if (cub->world.map[cub->ray.my][cub->ray.mx] == '1')
		color = 255;
	if (cub->ray.side == 1)
		color = color / 2;
	return (color);
}

void	line_start(t_cube *cub)

{
	int	l_height;

	l_height = (int)(SCREEN_H / cub->ray.perpwalldist);
	cub->ray.d_start = -l_height / 2 + SCREEN_H / 2;
	cub->ray.d_end = l_height / 2 + SCREEN_H / 2;
	if (cub->ray.d_start < 0)
		cub->ray.d_start = 0;
	if (cub->ray.d_end >= SCREEN_H)
		cub->ray.d_end = SCREEN_H - 1;
}

void	start_dda(t_cube *cub)

{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (cub->ray.distpx < cub->ray.distpy)
		{
			cub->ray.distpx += cub->ray.deltadistx;
			cub->ray.mx += cub->ray.stepx;
			cub->ray.side = 0;
		}
		else
		{
			cub->ray.distpy += cub->ray.deltadisty;
			cub->ray.my += cub->ray.stepy;
			cub->ray.side = 1;
		}
		if (cub->world.map[cub->ray.my][cub->ray.mx] == '1')
			hit = 1;
	}
	if (cub->ray.side == 0)
		cub->ray.perpwalldist = cub->ray.distpx - cub->ray.deltadistx;
	else
		cub->ray.perpwalldist = cub->ray.distpy - cub->ray.deltadisty;
}

void	set_distplayerbox(t_cube *cub)

{
	if (cub->ray.raydirx < 0)
	{
		cub->ray.stepx = -1;
		cub->ray.distpx = (cub->ray.posx - cub->ray.mx) * cub->ray.deltadistx;
	}
	else
	{
		cub->ray.stepx = 1;
		cub->ray.distpx = (cub->ray.mx + 1.0 - cub->ray.posx) \
		* cub->ray.deltadistx;
	}
	if (cub->ray.raydiry < 0)
	{
		cub->ray.stepy = -1;
		cub->ray.distpy = (cub->ray.posy - cub->ray.my) * cub->ray.deltadisty;
	}
	else
	{
		cub->ray.stepy = 1;
		cub->ray.distpy = (cub->ray.my + 1.0 - cub->ray.posy) \
		* cub->ray.deltadisty;
	}
}

void	set_value(t_cube *cub, int pixel)

{
	double	hypo;
	double	n;

	hypo = sqrt(pow(cub->ray.raydirx, 2) + pow(cub->ray.raydiry, 2));
	n = 2 * pixel / (double) SCREEN_W - 1;
	cub->ray.raydirx = cub->ray.dirx + cub->ray.planex * n;
	cub->ray.raydiry = cub->ray.diry + cub->ray.planey * n;
	if (cub->ray.raydirx == 0)
		cub->ray.deltadistx = 1e30;
	else
		cub->ray.deltadistx = fabs(hypo / cub->ray.raydirx);
	if (cub->ray.raydiry == 0)
		cub->ray.deltadisty = 1e30;
	else
		cub->ray.deltadisty = fabs(hypo / cub->ray.raydiry);
	cub->ray.mx = (int)cub->ray.posx;
	cub->ray.my = (int)cub->ray.posy;
}
