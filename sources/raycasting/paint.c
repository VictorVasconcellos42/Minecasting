/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 07:26:23 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/07/02 15:30:46 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_cube *cube, int x, int y, int color)
{
	char	*dst;

	dst = cube->mlx.addr + \
	(y * cube->mlx.line_len + x * (cube->mlx.bpp / 8));
	*(unsigned int *) dst = color;
}

void	draw_line(t_cube *cube, int *x, int *y, int color)
{
	int	i;

	i = x[0];
	while (i < x[1])
		put_pixel(cube, i++, y[0], color);
}

void	draw_vline(t_cube *cub, int x, int color)
{
	int	i;

	i = cub->ray.d_start;
	while (i < cub->ray.d_end)
		put_pixel(cub, x, i++, color);
}

void	draw_cube(t_cube *cube, int ceil, int floor)
{
	int	height;
	int	width;
	int	h_ceil;

	h_ceil = SCREEN_H * 0.5;
	height = -1;
	while (++height < h_ceil)
	{
		width = -1;
		while (++width < SCREEN_W)
			put_pixel(cube, width, height, ceil);
	}
	while (height < SCREEN_H)
	{
		width = -1;
		while (++width < SCREEN_W)
			put_pixel(cube, width, height, floor);
		height ++;
	}
}
