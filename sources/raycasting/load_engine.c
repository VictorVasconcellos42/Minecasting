/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:39:18 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/05/29 20:09:09 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	set_background(t_cube *cub)

{
	draw_cube(cub, 680, 600, 0x00FFFF00);
}

int	load_engine(t_cube *cub)

{
	int	x;
	int	color;

	x = -1;
	set_background(cub);
	while (++x < SCREEN_W)
	{
		init_vars(cub);
		set_value(cub, x);
		set_distplayerbox(cub);
		start_dda(cub);
		line_start(cub);
		color = set_color(cub);
		draw_vline(cub, x, color);
	}
	mlx_put_image_to_window(cub->mlx.init, cub->mlx.win, cub->mlx.img, 0, 0);
	return (x);
}
