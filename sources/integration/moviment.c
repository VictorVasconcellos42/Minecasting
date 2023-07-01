/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:39:19 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/01 01:07:36 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	moviment_engine(t_cube *cub, int key)
{
	double	*posx;
	double	*posy;
	double	*dirx;
	double	*diry;
	double	*speed;

	posx = &cub->ray.posx;
	posy = &cub->ray.posy;
	dirx = &cub->ray.dirx;
	diry = &cub->ray.diry;
	speed = &cub->ray.m_spd;

	if (key == KEY_W)
	{
		*posx += *dirx * *speed;
		*posy += *diry * *speed;
	}
	if (key == KEY_S)
	{
		*posx -= *dirx * *speed;
		*posy -= *diry * *speed;
	}
	if (key == KEY_A)
	{
		*posx -= *diry * *speed;
		*posy -= *dirx * *speed;
		printf ("(%.2f, %.2f)\n", cub->ray.posx, cub->ray.posy);
	}
	if (key == KEY_D)
	{
		*posx += *diry * *speed;
		*posy += *dirx * *speed;
		printf ("(%.2f, %.2f)\n", cub->ray.posx, cub->ray.posy);
	}
}

void	look_engine(t_cube *cub, int key, double *dirx, double *diry)
{
	double	*plny;
	double	*plnx;
	double	odirx;
	double	oplanex;

	odirx = cub->ray.dirx;
	oplanex = cub->ray.planex;
	plnx = &cub->ray.planex;
	plny = &cub->ray.planey;

	if (key == KEY_ARR_LEFT)
	{
		*dirx = (*dirx * cos(-cub->ray.r_spd) - *diry * sin(-cub->ray.r_spd));
		*diry = (odirx * sin(-cub->ray.r_spd) + *diry * cos(-cub->ray.r_spd));
		*plnx = (*plnx * cos(-cub->ray.r_spd) - *plny * sin(-cub->ray.r_spd));
		*plny = (oplanex * sin(-cub->ray.r_spd) + *plny * cos(-cub->ray.r_spd));
	}
	if (key == KEY_ARR_RIGHT)
	{
		*dirx = (*dirx * cos(cub->ray.r_spd) - *diry * sin(cub->ray.r_spd));
		*diry = (odirx * sin(cub->ray.r_spd) + *diry * cos(cub->ray.r_spd));
		*plnx = (*plnx * cos(cub->ray.r_spd) - *plny * sin(cub->ray.r_spd));
		*plny = (oplanex * sin(cub->ray.r_spd) + *plny * cos(cub->ray.r_spd));
	}
}
