/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freezed.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:33:26 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/07 21:34:57 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_mlx(t_mlx *mlx)
{
	if (mlx->img)
	{
		mlx_destroy_image(mlx->init, mlx->img);
		mlx->img = 0;
	}
	if (mlx->win)
	{
		mlx_destroy_window(mlx->init, mlx->win);
		mlx->win = 0;
	}
	if (mlx->init)
	{
		mlx_destroy_display(mlx->init);
		free(mlx->init);
		mlx->init = 0;
	}
}

void	free_map(t_map *map)
{
	if (map->map)
	{
		free_matrix(map->map);
		map->map = 0;
	}
	if (map->texture)
	{
		free_matrix(map->texture);
		map->texture = 0;
	}
	if (map->colors)
	{
		free (map->colors[0]);
		free (map->colors[1]);
		free (map->colors);
		map->colors = 0;
	}
}

void	free_text(t_text ***ptr, t_mlx *mlx)
{
	t_text	**text;
	int		i;

	text = *ptr;
	i = -1;
	while (*(text + ++i))
	{
		mlx_destroy_image(mlx->init, text[i]->addr);
		free (text[i]);
		text[i] = 0;
	}
	free (text);
	*ptr = 0;
}
