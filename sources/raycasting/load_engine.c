/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:39:18 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/06/23 14:49:02 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	set_background(t_cube *cub)

{
	draw_cube(cub, 600, 600, 0x00FF00Ff);
	draw_cube(cub, 600, 300, 0x00000000);
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
