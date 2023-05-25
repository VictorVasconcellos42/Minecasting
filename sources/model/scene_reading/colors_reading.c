/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_reading.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:51:04 by jsantann          #+#    #+#             */
/*   Updated: 2023/05/17 15:31:17 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*get_floor(char **matrix)
{
	int		i;
	int		size;
	int		start;
	char	*res;

	size = 0;
	i = 0;
	while (matrix[i])
	{
		if (ft_strnstr(matrix[i], "F ", ft_strlen(matrix[i])))
		{
			start = count_space(matrix[i]);
			if (locate_char(matrix[i], start, 'F'))
			{
				size = locate_char(matrix[i], start, 'F');
				break ;
			}
		}
		i++;
	}
	res = create_vector(matrix[i], start, size);
	if (res)
		return (res);
	return (NULL);
}

char	*get_ceiling(char **matrix)
{
	int		i;
	int		size;
	int		start;
	char	*res;

	size = 0;
	i = 0;
	while (matrix[i])
	{
		if (ft_strnstr(matrix[i], "C ", ft_strlen(matrix[i])))
		{
			start = count_space(matrix[i]);
			if (locate_char(matrix[i], start, 'C'))
			{
				size = locate_char(matrix[i], start, 'C');
				break ;
			}
		}
		i++;
	}
	res = create_vector(matrix[i], start, size);
	if (res)
		return (res);
	return (NULL);
}
