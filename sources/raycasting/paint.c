/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 07:26:23 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/07/07 11:55:09 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_cube *cube, int x, int y, int color)
{
	char	*dst;

	if ((x < 0 || x > (SCREEN_W)) || (y < 0 || y > (SCREEN_H)))
		return ;
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

void	draw_vline(t_cube *cub, int x, t_text *texture)
{
	int				i;
	double			step;
	float			y_tx;
	float			x_tx;
	char			*ptr;
	unsigned int	color;

	i = cub->ray.d_start;
	y_tx = 0.0;
	step = ((double)texture->height / (cub->ray.d_end - cub->ray.d_start));
	if (cub->ray.side == 0)
		x_tx = cub->ray.posy + cub->ray.perpwalldist * cub->ray.raydiry;
	else
		x_tx = cub->ray.posx + cub->ray.perpwalldist * cub->ray.raydirx;
	x_tx -= floor(x_tx);
	while (i < cub->ray.d_end)
	{
		ptr = (texture->head + ((int)floor(y_tx) * texture->slen
			+ (int)(x_tx * texture->width) * (texture->bpp / 8)));
		color = *(unsigned int *)ptr;
		y_tx += step;
		put_pixel(cub, x, i++, color);
	}
}

void	draw_cube(t_cube *cube, int ceil, int floor)
{
	int	height;
	int	width;
	int	h_ceil;

	h_ceil = (SCREEN_H - 1) * 0.5;
	height = -1;
	while (++height < h_ceil)
	{
		width = -1;
		while (++width < SCREEN_W)
			put_pixel(cube, width, height, ceil);
	}
	while (height < (SCREEN_H - 1))
	{
		width = -1;
		while (++width < SCREEN_W)
			put_pixel(cube, width, height, floor);
		height ++;
	}
}
