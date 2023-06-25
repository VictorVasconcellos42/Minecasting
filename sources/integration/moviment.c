/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:39:19 by thfirmin          #+#    #+#             */
/*   Updated: 2023/06/25 16:39:20 by thfirmin         ###   ########.fr       */
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
	printf("moviment activate (%fx%f)\n", cub->ray.posx, cub->ray.posy);
}

void	look_engine(t_cube *cub, int key)
{
	static int	dx = 1;
	static int	dy = 1;

	if (key == KEY_ARR_LEFT)
	{
		printf ("((%.2f - %.2f = %.2f), (%.2f - %.2f = %.2f))\n", \
			cub->ray.dirx, (0.1 * dx), (cub->ray.dirx - (0.1 * dx)), \
			cub->ray.diry, (0.1 * dy), (cub->ray.diry - (0.1 * dy)));
		cub->ray.dirx -= (0.1 * dx);
		cub->ray.diry -= (0.1 * dy);
	}
	if (key == KEY_ARR_RIGHT)
	{
		printf ("((%.2f + %.2f = %.2f), (%.2f - %.2f = %.2f))\n", \
			cub->ray.dirx, (0.1 * dx), (cub->ray.dirx + (0.1 * dx)), \
			cub->ray.diry, (0.1 * dy), (cub->ray.diry - (0.1 * dy)));
		cub->ray.dirx += (0.1 * dx);
		cub->ray.diry -= (0.1 * dy);
	}
}
