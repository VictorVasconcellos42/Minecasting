/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:48:02 by jsantann          #+#    #+#             */
/*   Updated: 2023/07/07 20:27:31 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

// Mount ceil color config in array of int
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

// Mount floor color config in array of int
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

// Read ceil/floor seeting lines and extract ceil/floor colors setting
int	**colorstrtoint(char **colors)
{
	int	**matrix;

	matrix = ft_calloc(sizeof(int *), 3);
	matrix[C] = filling_celling(colors[C]);
	matrix[F] = filling_floor(colors[F]);
	free_matrix(colors);
	return (matrix);
}
