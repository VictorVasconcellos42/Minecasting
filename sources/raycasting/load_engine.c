/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:39:18 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/07/02 15:31:30 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void    render_box(t_cube *cub, int x, int y, int len, int color)
{
	int i = y + len;
	int j = x + len;
	int old_x = x;

	while(y < i)
	{
		x = old_x;
		while (x < j)
			put_pixel(cub, x++, y, color);
		y++;
	}
}

void DDA(t_cube *cub, int X0, int Y0, int X1, int Y1)
{
	int dx = X1 - X0;
	int dy = Y1 - Y0;

	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	float Xinc = dx / (float)steps;
	float Yinc = dy / (float)steps;
	if (isinf(Xinc))
		Xinc = 0;
	if (isinf(Yinc))
		Yinc = 0;

	float X = X0;
	float Y = Y0;
	for (int i = 0; i <= steps; i++) {
		put_pixel(cub, round(X), round(Y), 0x0000FF00); // put pixel at (X,Y)
		X += Xinc; // increment in x at each step
		Y += Yinc; // increment in y at each step
	}
}

void    draw_map(t_cube *cub)
{
	int y = 0;
	int x = 0;

	while(cub->world.map[y])
	{
		x = 0;
		while(cub->world.map[y][x])
		{
			if (cub->world.map[y][x] == '0')
				render_box(cub, x*8, y*8, 8, 0xFFFFFFFF);
			if (cub->world.map[y][x] == '1')
				render_box(cub, x*8, y*8, 8, 0xFF000000);
			x++;
		}
		y++;
	}
	render_box(cub, cub->ray.posx*8, cub->ray.posy*8, 4, 0xFF0000FF);
}

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
	int	x;
	int	color;

	x = -1;
	set_background(cub);
	draw_map(cub); //
	while (++x < SCREEN_W)
	{
		update_vars(cub);
		set_value(cub, x);
		set_distplayerbox(cub);
		start_dda(cub);
		DDA(cub, cub->ray.posx*8, cub->ray.posy*8,
			(cub->ray.posx+(cub->ray.perpwalldist*cub->ray.dirx))*8, (cub->ray.posy+(cub->ray.perpwalldist*cub->ray.diry))*8); //
		line_start(cub);
		color = set_color(cub);
		draw_vline(cub, x, color);
	}
	mlx_put_image_to_window(cub->mlx.init, cub->mlx.win, cub->mlx.img, 0, 0);
	return (x);
}
