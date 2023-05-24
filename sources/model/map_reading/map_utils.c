/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 07:56:45 by jsantann          #+#    #+#             */
/*   Updated: 2023/05/17 14:33:01 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	is_map(char *str)
{
	int	i;

	i = 0;
	if (str[0] == ' ')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '1')
			return (1);
		else
			return (0);
	}
	else if (str[0] == '1')
		return (1);
	else
		return (0);
}

int	start_map(char **matrix)
{
	int		i;

	i = 0;
	while (matrix[i])
	{
		if (is_map(matrix[i]))
			return (i);
		i++;
	}
	return (0);
}

int	size_map(char **matrix, int start)
{
	int	size;

	size = 0;
	while (matrix[start])
	{
		start++;
		size++;
	}
	return (size);
}
