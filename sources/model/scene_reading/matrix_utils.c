/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:33:26 by jsantann          #+#    #+#             */
/*   Updated: 2023/05/29 20:59:50 by jsantann         ###   ########.fr       */
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
	int	g;

	i = 0;
	g = 0;
	printf("%s\n", cub->d_map.resolution);
	while (cub->d_map.texture[i])
		printf("%s\n", cub->d_map.texture[i++]);
	i = 0;
	printf("%s\n", cub->d_map.sprites);
	i = 0;
	while (i < 2)
	{
		while (g < 3)
			printf("%d ", cub->d_map.colors[i][g++]);
		printf("\n");
		g = 0;
		i++;
	}
	i = 0;
	while (cub->d_map.map[i])
		printf("%s", cub->d_map.map[i++]);
}

char	*create_spaces(int len)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char) * len + 2);
	while (i < len)
	{
		tmp[i] = ' ';
		i++;
	}
	tmp[i] = '\n';
	tmp[i + 1] = '\0';
	return (tmp);
}
