/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:39:19 by thfirmin          #+#    #+#             */
/*   Updated: 2023/06/30 16:12:18 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	moviment_engine(t_cube *cub, int key)
{
	if (key == KEY_W)
		cub->ray.posy -= 0.1;
	if (key == KEY_S)
		cub->ray.posy += 0.1;
	if (key == KEY_A)
		cub->ray.posx -= 0.1;
	if (key == KEY_D)
		cub->ray.posx += 0.1;
}

void	look_engine(t_cube *cub, int key)
{
	//double	ang;
	//int		sum;
	double	odirx;
	double	oplanex;

	odirx = cub->ray.dirx;
	oplanex = cub->ray.planex;
	//if (((cub->ray.angle >= 180) && (cub->ray.angle <= 360)) || cub->ray.angle == 0)
	//	sum = 1;
	//else
	//	sum = -1;

	if (key == KEY_ARR_RIGHT)
	{
		cub->ray.dirx = (cub->ray.dirx * cos(-cub->ray.rspeed) - cub->ray.diry * sin(-cub->ray.rspeed));
		cub->ray.diry = (odirx * sin(-cub->ray.rspeed) + cub->ray.diry * cos(-cub->ray.rspeed));
		cub->ray.planex = (cub->ray.planex * cos(-cub->ray.rspeed) - cub->ray.planey * sin(-cub->ray.rspeed));
		cub->ray.planey = (oplanex * sin(-cub->ray.rspeed) + cub->ray.planey * cos(-cub->ray.rspeed));
	}
	if (key == KEY_ARR_LEFT)
	{
		cub->ray.dirx = (cub->ray.dirx * cos(cub->ray.rspeed) - cub->ray.diry * sin(cub->ray.rspeed));
		cub->ray.diry = (odirx * sin(cub->ray.rspeed) + cub->ray.diry * cos(cub->ray.rspeed));
		cub->ray.planex = (cub->ray.planex * cos(cub->ray.rspeed) - cub->ray.planey * sin(cub->ray.rspeed));
		cub->ray.planey = (oplanex * sin(cub->ray.rspeed) + cub->ray.planey * cos(cub->ray.rspeed));
	}
	if (key == KEY_ARR_UP)
	{
		cub->ray.rspeed = (cub->ray.rspeed + 0.1);
		printf ("RotateSpeed: %f\n", cub->ray.rspeed);
	}
	else if (key == KEY_ARR_DWN)
	{
		cub->ray.rspeed = (cub->ray.rspeed - 0.1);
		printf ("RotateSpeed: %f\n", cub->ray.rspeed);
	}
	//printf ("(%f, %f) | ", cub->ray.dirx, cub->ray.diry);
	//printf (" %dº(%f)\n", cub->ray.angle, ang);
}
