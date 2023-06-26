/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:30:57 by jsantann          #+#    #+#             */
/*   Updated: 2023/06/26 16:36:18 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

// Validade texture setting
void	texture_validation(char **texture)
{
	texture_null(texture);
	texture_little(texture);
	texture_xpm(texture);
	texture_path(texture);
}

void	lines_error(void)
{
	ft_putstr_fd("Invalid Lines\n", 2);
	exit(0);
}

void	invalid_lines(char **file)
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
		lines_error();
}
