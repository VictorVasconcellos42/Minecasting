/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 07:26:23 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/05/29 17:22:01 by vde-vasc         ###   ########.fr       */
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

void	draw_cube(t_cube *cube, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
			put_pixel(cube, j++, i, color);
		i++;
	}
}
