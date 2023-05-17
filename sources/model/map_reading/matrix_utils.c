/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:33:26 by jsantann          #+#    #+#             */
/*   Updated: 2023/05/17 17:22:37 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	count_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	print_matrix(t_cube *cub)
{
	int	i;

	i = 0;
	printf("%s\n", cub->resolution);
	while (cub->texture[i])
		printf("%s\n", cub->texture[i++]);
	i = 0;
	printf("%s\n", cub->sprites);
	i = 0;
	while (cub->colors[i])
		printf("%s\n", cub->colors[i++]);
	i = 0;
	while (cub->map[i])
		printf("%s", cub->map[i++]);
}
