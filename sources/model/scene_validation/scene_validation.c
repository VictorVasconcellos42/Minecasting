/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:30:57 by jsantann          #+#    #+#             */
/*   Updated: 2023/05/29 15:15:36 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	texture_validation(t_cube *cub)
{
	error_permission(cub->d_map.texture[0] + 3);
	error_permission(cub->d_map.texture[1] + 3);
	error_permission(cub->d_map.texture[2] + 3);
	error_permission(cub->d_map.texture[3] + 3);
}

void	color_validation(t_cube *cub)
{
	int	i[3];
	int	position;

	position = 2;
	i[0] = get_r(cub->d_map.colors[0], &position);
	i[1] = get_g(cub->d_map.colors[0], &position);
	i[2] = get_b(cub->d_map.colors[0], position + 1);
	if (i[0] < 0 || i[0] > 255)
		ft_putstr_fd("Error\n", 2);
	if (i[1] < 0 || i[1] > 255)
		ft_putstr_fd("Error\n", 2);
	if (i[2] < 0 || i[2] > 255)
		ft_putstr_fd("Error\n", 2);
}

void	scene_validation(t_cube *cub)
{
	texture_validation(cub);
	color_validation(cub);
}
