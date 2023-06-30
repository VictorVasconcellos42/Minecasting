/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:39:19 by thfirmin          #+#    #+#             */
/*   Updated: 2023/06/30 17:02:44 by thfirmin         ###   ########.fr       */
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
                cub->ray.posx -=  (1 - fabs(cub->ray.dirx)) / 10;
                cub->ray.posy -= (1 - fabs(cub->ray.diry)) / 10;
		printf ("dpois: (%.2f, %.2f)\n", cub->ray.posx, cub->ray.posy);
	}
	if (key == KEY_D)
	{
		printf ("antes: (%.2f, %.2f) | ", cub->ray.posx, cub->ray.posy);
                cub->ray.posx +=  (1 - fabs(cub->ray.dirx)) / 10;
                cub->ray.posy += (1 - fabs(cub->ray.diry)) / 10;
		printf ("dpois: (%.2f, %.2f)\n", cub->ray.posx, cub->ray.posy);
	}
}

void	look_engine(t_cube *cub, int key)
{
	double	odirx;
	double	oplanex;

	odirx = cub->ray.dirx;
	oplanex = cub->ray.planex;

	if (key == KEY_ARR_LEFT)
	{
		cub->ray.dirx = (cub->ray.dirx * cos(-cub->ray.rspeed) - cub->ray.diry * sin(-cub->ray.rspeed));
		cub->ray.diry = (odirx * sin(-cub->ray.rspeed) + cub->ray.diry * cos(-cub->ray.rspeed));
		cub->ray.planex = (cub->ray.planex * cos(-cub->ray.rspeed) - cub->ray.planey * sin(-cub->ray.rspeed));
		cub->ray.planey = (oplanex * sin(-cub->ray.rspeed) + cub->ray.planey * cos(-cub->ray.rspeed));
	}
	if (key == KEY_ARR_RIGHT)
	{
		cub->ray.dirx = (cub->ray.dirx * cos(cub->ray.rspeed) - cub->ray.diry * sin(cub->ray.rspeed));
		cub->ray.diry = (odirx * sin(cub->ray.rspeed) + cub->ray.diry * cos(cub->ray.rspeed));
		cub->ray.planex = (cub->ray.planex * cos(cub->ray.rspeed) - cub->ray.planey * sin(cub->ray.rspeed));
		cub->ray.planey = (oplanex * sin(cub->ray.rspeed) + cub->ray.planey * cos(cub->ray.rspeed));
	}
}
