/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:02:46 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/06/30 20:06:02 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	init_vars(t_cube *cub)
{
	cub->ray.planex = 0.66;
	cub->ray.r_spd = 0.1;
	cub->ray.m_spd = 0.1;
}

void	update_vars(t_cube *cub)
{
	cub->ray.time = 0;
	cub->ray.stepx = 0;
	cub->ray.stepy = 0;
	cub->ray.side = 0;
}

