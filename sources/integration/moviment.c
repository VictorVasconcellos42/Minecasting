/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:39:19 by thfirmin          #+#    #+#             */
/*   Updated: 2023/06/25 18:05:52 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	moviment_engine(t_cube *cub, int key)
{
	(void) cub;
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
	double	ang;

	if (key == KEY_ARR_RIGHT)
		cub->ray.angle = ((cub->ray.angle + 1) % 360);
	if (key == KEY_ARR_LEFT)
	{
		if (cub->ray.angle == 1)
			cub->ray.angle = 360;
		else
			cub->ray.angle--;
	}
	ang = (cub->ray.angle * (M_PI / 180));
	cub->ray.dirx = cos(ang);
	cub->ray.diry = sin(ang);
	printf ("(%f, %f) | ", cub->ray.dirx, cub->ray.diry);
	printf (" %dº(%f)\n", cub->ray.angle, ang);
}
