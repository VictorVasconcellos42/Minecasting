/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 07:26:23 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/05/23 10:13:55 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_cube *cube, int x, int y, int color)
{
	char	*dst;

	dst = cube->addr + (y * cube->line_len + x * (cube->bpp / 8));
	*(unsigned int*)dst = color;
}

void	draw_line(t_cube *cube, int x1, int x2, int y, int color)

{
	int i;

	i = x1;
	while (i < x2)
		put_pixel(cube, i++, y, color);
}

void	draw_vline(t_cube *cube, int x, int y1, int y2, int color)

{
	int i;

	i = y1;
	while (i < y2)
		put_pixel(cube, x, i++, color);
}

void	draw_cube(t_cube *cube, int x, int y, int color)
{
	int i;
	int j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
			put_pixel(cube, j++, i, color);
		i++;
	}
}
