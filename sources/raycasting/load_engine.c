/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:39:18 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/06/30 16:48:47 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	set_background(t_cube *cub)

{
	int	r;
	int	g;
	int	b;

	r = cub->world.colors[C][0];
	g = cub->world.colors[C][1];
	b = cub->world.colors[C][2];
	draw_cube(cub, 600, 600, rgb_to_color(r, g, b));
	r = cub->world.colors[F][0];
	g = cub->world.colors[F][1];
	b = cub->world.colors[F][2];
	draw_cube(cub, 600, 300, rgb_to_color(r, g, b));
}

int	load_engine(t_cube *cub)
{
	int	x;
	int	color;

	x = -1;
	set_background(cub);
	while (++x < SCREEN_W)
	{
		update_vars(cub);
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
