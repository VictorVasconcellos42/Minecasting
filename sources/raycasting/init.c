/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:02:46 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/07/07 18:23:19 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

// Initialize cub struct variables
void	init_vars(t_cube *cub)
{
	cub->ray.r_spd = 0.05;
	cub->ray.m_spd = 0.1;
	cub->ray.rad90 = (M_PI / 2);
}

// Constant update of cub struct variables
void	update_vars(t_cube *cub)
{
	cub->ray.time = 0;
	cub->ray.stepx = 0;
	cub->ray.stepy = 0;
	cub->ray.side = 0;
}
