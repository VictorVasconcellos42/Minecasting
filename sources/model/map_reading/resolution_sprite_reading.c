/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution_sprite_reading.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:48:30 by jsantann          #+#    #+#             */
/*   Updated: 2023/05/17 17:16:52 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*get_resolution(char **matrix)
{
	int		i;
	int		size;
	int		start;
	char	*res;

	size = 0;
	i = 0;
	while (matrix[i])
	{
		if (ft_strnstr(matrix[i], "R ", ft_strlen(matrix[i])))
		{
			start = count_space(matrix[i]);
			if (locate_char(matrix[i], start, 'R'))
			{
				size = locate_char(matrix[i], start, 'R');
				break ;
			}
		}
		i++;
	}
	res = create_vector(matrix[i], start, size);
	return (res);
}

char	*get_sprite(char **matrix)
{
	int		i;
	int		size;
	int		start;
	char	*res;

	size = 0;
	i = 0;
	while (matrix[i])
	{
		if (ft_strnstr(matrix[i], "S ", ft_strlen(matrix[i])))
		{
			start = count_space(matrix[i]);
			if (locate_char(matrix[i], start, 'S'))
			{
				size = locate_char(matrix[i], start, 'S');
				break ;
			}
		}
		i++;
	}
	res = create_vector(matrix[i], start, size);
	return (res);
}
