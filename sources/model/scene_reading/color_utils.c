/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:48:02 by jsantann          #+#    #+#             */
/*   Updated: 2023/05/29 17:27:19 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	*filling_celling(char *color)
{
	int	*array;
	int	position;

	position = 2;
	array = malloc(sizeof(int) * 3);
	array[0] = get_r(color, &position);
	array[1] = get_g(color, &position);
	array[2] = get_b(color, position + 1);
	return (array);
}

int	*filling_floor(char *color)
{
	int	*array;
	int	position;

	position = 2;
	array = malloc(sizeof(int) * 3);
	array[0] = get_r(color, &position);
	array[1] = get_g(color, &position);
	array[2] = get_b(color, position + 1);
	return (array);
}

int	**colorstrtoint(char **colors)
{
	int	**matrix;

	matrix = ft_calloc(sizeof(int *), 3);
	matrix[C] = filling_celling(colors[C]);
	matrix[F] = filling_floor(colors[F]);
	free_matrix(colors);
	return (matrix);
}
