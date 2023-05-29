/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:02:46 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/05/29 20:08:55 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	init_vars(t_cube *cub)

{
	cub->ray.posx = 9;
	cub->ray.posy = 10;
	cub->ray.dirx = 0;
	cub->ray.diry = -1;
	cub->ray.planex = 0.66;
	cub->ray.planey = 0;
	cub->ray.time = 0;
	cub->ray.stepx = 0;
	cub->ray.stepy = 0;
	cub->ray.side = 0;
}
