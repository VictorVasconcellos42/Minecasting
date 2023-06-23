/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:32:37 by jsantann          #+#    #+#             */
/*   Updated: 2023/05/29 21:00:49 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	texture_null(char **texture)
{
	if (!texture[NO] || !texture[EA] || !texture[SO] || !texture[WE])
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Any texture not defined", 2);
		exit(0);
	}
}

void	texture_little(char **texture)
{
	int	size1;
	int	size2;
	int	size3;
	int	size4;

	size1 = ft_strlen(texture[0] + 3);
	size2 = ft_strlen(texture[1] + 3);
	size3 = ft_strlen(texture[2] + 3);
	size4 = ft_strlen(texture[3] + 3);
	if (size1 < 5 || size2 < 5 || size3 < 5 || size4 < 5)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Invalid len\n", 2);
		exit(0);
	}
}

void	texture_xpm(char **texture)
{
	int	size;

	size = 0;
	while (texture[0][size + 4])
	{
		size++;
	}
	if (ft_strncmp(texture[0] + size, ".xpm", 4))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Invalid xpm\n", 2);
		exit(0);
	}
}

void	texture_path(char **texture)
{
	error_permission(texture[NO] + 3);
	error_permission(texture[SO] + 3);
	error_permission(texture[WE] + 3);
	error_permission(texture[EA] + 3);
}
