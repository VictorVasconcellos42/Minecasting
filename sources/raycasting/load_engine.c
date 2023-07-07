/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:39:18 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/07/07 12:00:42 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	draw_map(t_cube *cub);

void	set_background(t_cube *cub)
{
	int	**clr;
	int	ceil;
	int	floor;

	clr = cub->world.colors;
	ceil = rgb_to_color(clr[C][0], clr[C][1], clr[C][2]);
	floor = rgb_to_color(clr[F][0], clr[F][1], clr[F][2]);
	draw_cube(cub, ceil, floor);
}

int	load_engine(t_cube *cub)
{
	int		x;
	t_text	*texture;

	x = -1;
	set_background (cub);
	while (++x < SCREEN_W)
	{
		update_vars(cub);
		set_value(cub, x);
		set_distplayerbox(cub);
		start_dda(cub);
		line_start (cub);
		texture = set_texture (cub);
		draw_vline (cub, x, texture);
		if (cub->map_switch)
			draw_map(cub);
	}
	mlx_put_image_to_window(cub->mlx.init, cub->mlx.win, cub->mlx.img, 0, 0);
	return (x);
}
