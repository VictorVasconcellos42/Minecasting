/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:08:17 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/05 00:31:43 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	dda(t_cube *cub, int steps, float xinc, float yinc);

static void	sub_dda(t_cube *cub, int x1, int y1);

static void	render_box(t_cube *cub, int x, int y, int color);

void	draw_map(t_cube *cub)
{
	int		y;
	int		x;
	t_ray	ray;

	x = 0;
	y = 0;
	ray = cub->ray;
	while (cub->world.map[y])
	{
		x = 0;
		while (cub->world.map[y][x])
		{
			if (cub->world.map[y][x] == '0')
				render_box(cub, x * 8, y * 8, 0xFFFFFFFF);
			if (cub->world.map[y][x] == '1')
				render_box(cub, x * 8, y * 8, 0xFF000000);
			x++;
		}
		y++;
	}
	render_box (cub, cub->ray.posx * 8, cub->ray.posy * 8, 0xFF0000FF);
	sub_dda (cub, (ray.posx + (ray.perpwalldist * ray.dirx)) * 8,
		(ray.posy + (ray.perpwalldist * ray.diry)) * 8);
}

static void	render_box(t_cube *cub, int x, int y, int color)
{
	int	i;
	int	j;
	int	len;
	int	old_x;

	len = 8;
	if (color == (int)0xFF0000FF)
		len = 4;
	i = y + len;
	j = x + len;
	old_x = x;
	while (y < i)
	{
		x = old_x;
		while (x < j)
			put_pixel(cub, x++, y, color);
		y++;
	}
}

static void	sub_dda(t_cube *cub, int x1, int y1)
{
	int		x0;
	int		y0;
	int		steps;
	float	xinc;
	float	yinc;

	x0 = cub->ray.posx * 8;
	y0 = cub->ray.posy * 8;
	if (abs(x1 - x0) > abs(y1 - y0))
		steps = abs(x1 - x0);
	else
		steps = abs(y1 - y0);
	xinc = ((x1 - x0) / (float)steps);
	yinc = ((y1 - y0) / (float)steps);
	if (isinf(xinc))
		xinc = 0;
	if (isinf(yinc))
		yinc = 0;
	dda(cub, steps, xinc, yinc);
}

static void	dda(t_cube *cub, int steps, float xinc, float yinc)
{
	int	x;
	int	y;
	int	i;

	x = cub->ray.posx * 8;
	y = cub->ray.posy * 8;
	i = -1;
	while (++i <= steps)
	{
		put_pixel(cub, round(x), round(y), 0x0000FF00);
		x += xinc;
		y += yinc;
	}
}
