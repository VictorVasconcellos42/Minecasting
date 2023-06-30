/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:39:19 by thfirmin          #+#    #+#             */
/*   Updated: 2023/06/28 14:52:01 by thfirmin         ###   ########.fr       */
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
	double	ang;

	if (key == KEY_ARR_RIGHT)
		cub->ray.angle = ((cub->ray.angle + 1) % 360);
	if (key == KEY_ARR_LEFT)
	{
		if (cub->ray.angle <= 1)
			cub->ray.angle = (360 - (1 - cub->ray.angle));
		else
			cub->ray.angle--;
	}
	ang = (cub->ray.angle * (M_PI / 180));
	cub->ray.dirx = cos(ang);
	cub->ray.diry = sin(ang);
	cub->ray.planex += 0.01;
	cub->ray.planey += 0.01;
	printf ("(%f, %f) | ", cub->ray.dirx, cub->ray.diry);
	printf (" %dº(%f)\n", cub->ray.angle, ang);
}
