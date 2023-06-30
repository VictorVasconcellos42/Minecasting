/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:39:19 by thfirmin          #+#    #+#             */
/*   Updated: 2023/06/30 20:15:00 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	moviment_engine(t_cube *cub, int key)
{
	if (key == KEY_W)
	{
		cub->ray.posx += cub->ray.dirx * 0.1;
		cub->ray.posy += cub->ray.diry * 0.1;
	}
	if (key == KEY_S)
	{
		cub->ray.posx -= cub->ray.dirx * 0.1;
		cub->ray.posy -= cub->ray.diry * 0.1;
	}
	if (key == KEY_A)
	{
		printf ("antes: (%.2f, %.2f) | ", cub->ray.posx, cub->ray.posy);
		cub->ray.posx -= (1 - fabs(cub->ray.dirx)) / 10;
		cub->ray.posy -= (1 - fabs(cub->ray.diry)) / 10;
		printf ("dpois: (%.2f, %.2f)\n", cub->ray.posx, cub->ray.posy);
	}
	if (key == KEY_D)
	{
		printf ("antes: (%.2f, %.2f) | ", cub->ray.posx, cub->ray.posy);
		cub->ray.posx += (1 - fabs(cub->ray.dirx)) / 10;
		cub->ray.posy += (1 - fabs(cub->ray.diry)) / 10;
		printf ("dpois: (%.2f, %.2f)\n", cub->ray.posx, cub->ray.posy);
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
