/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:27:45 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/07/07 19:43:31 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	freedom_project(void **matriz)

{
	while (*matriz)
	{
		free(*matriz);
		matriz++;
	}
	free(matriz);
	matriz = NULL;
}

void	block_buster(t_cube *cub)

{
	freedom_project((void **)cub->world.map);
	freedom_project((void **)cub->world.texture);
	freedom_project((void **)cub->world.colors);
}