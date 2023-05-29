/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_reading.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:51:04 by jsantann          #+#    #+#             */
/*   Updated: 2023/05/17 16:28:04 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*get_north(char **matrix)
{
	int		i;
	int		size;
	int		start;
	char	*res;

	i = 0;
	start = 0;
	size = 0;
	while (matrix[i])
	{
		if (ft_strnstr(matrix[i], "NO ", ft_strlen(matrix[i])))
		{
			start = count_space(matrix[i]);
			size = count_n(matrix[i], start);
			break ;
		}
		i++;
	}	
	res = create_vector(matrix[i], start, size);
	if (res)
		return (res);
	return (NULL);
}

char	*get_south(char **matrix)
{
	int		i;
	int		size;
	int		start;
	char	*res;

	i = 0;
	start = 0;
	size = 0;
	while (matrix[i])
	{
		if (ft_strnstr(matrix[i], "SO ", ft_strlen(matrix[i])))
		{
			start = count_space(matrix[i]);
			size = count_n(matrix[i], start);
			break ;
		}
		i++;
	}
	res = create_vector(matrix[i], start, size);
	if (res)
		return (res);
	return (NULL);
}

char	*get_west(char **matrix)
{
	int		i;
	int		size;
	int		start;
	char	*res;

	i = 0;
	start = 0;
	size = 0;
	while (matrix[i])
	{
		if (ft_strnstr(matrix[i], "WE ", ft_strlen(matrix[i])))
		{
			start = count_space(matrix[i]);
			size = count_n(matrix[i], start);
			break ;
		}
		i++;
	}
	res = create_vector(matrix[i], start, size);
	if (res)
		return (res);
	return (NULL);
}

char	*get_east(char **matrix)
{
	int		i;
	int		size;
	int		start;
	char	*res;

	i = 0;
	size = 0;
	start = 0;
	while (matrix[i])
	{
		if (ft_strnstr(matrix[i], "EA ", ft_strlen(matrix[i])))
		{
			start = count_space(matrix[i]);
			size = count_n(matrix[i], start);
			break ;
		}
		i++;
	}
	res = create_vector(matrix[i], start, size);
	if (res)
		return (res);
	return (NULL);
}
