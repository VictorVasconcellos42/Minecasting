/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:30:57 by jsantann          #+#    #+#             */
/*   Updated: 2023/07/07 21:40:53 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

// Validade texture setting
void	texture_validation(char **texture, t_cube *cub)
{
	texture_null(texture, cub);
	texture_little(texture, cub);
	texture_xpm(texture, cub);
	texture_path(texture, cub);
}

void	lines_error(t_cube *cub)
{
	ft_putstr_fd("Invalid Lines\n", 2);
	block_buster(cub);
	exit(0);
}

void	invalid_lines(char **file, t_cube *cub)
{
	int	lines_filled;
	int	i;

	i = 0;
	lines_filled = 0;
	while (i < start_map(file))
	{
		if (ft_strlen(file[i]) > 1)
			lines_filled++;
		i++;
	}
	if (lines_filled > 6)
		lines_error(cub);
}
