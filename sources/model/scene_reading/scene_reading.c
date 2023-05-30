/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_reading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:26:34 by jsantann          #+#    #+#             */
/*   Updated: 2023/05/29 18:03:50 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	get_file(int fd, t_cube *cub)
{
	char	*gnl;
	char	*res;
	char	**matrix;

	res = ft_strdup("");
	while (42)
	{
		gnl = get_next_line(fd);
		if (!gnl)
			break ;
		gnl = ft_strjoin_gnl(gnl, "$");
		res = ft_strjoin_gnl(res, gnl);
		free(gnl);
	}
	matrix = ft_split(res, '$');
	cub->d_map.texture = get_texture_map(matrix);
	cub->d_map.colors = colorstrtoint(get_colors(matrix));
	cub->d_map.map = get_map(matrix);
	cub->d_map.resolution = get_resolution(matrix);
	cub->d_map.sprites = get_sprite(matrix);
	texture_validation(cub->d_map.texture);
	print_matrix(cub);
	free(res);
	free_matrix(matrix);
}

char	**get_texture_map(char **matrix)
{
	char	**texture;

	texture = ft_calloc(sizeof(char *), 5);
	texture[NO] = get_north(matrix);
	texture[EA] = get_east(matrix);
	texture[SO] = get_south(matrix);
	texture[WE] = get_west(matrix);
	return (texture);
}

char	**get_colors(char **matrix)
{
	char	**colors;

	colors = ft_calloc(sizeof(char *), 3);
	colors[F] = get_floor(matrix);
	colors[C] = get_ceiling(matrix);
	if (!colors[F] || !colors[C])
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Any color not defined\n", 2);
		free_matrix(matrix);
		free_matrix(colors);
		exit(0);
	}
	return (colors);
}

char	**get_map(char **matrix)
{
	int		size;
	int		start;
	int		max;
	int		i;
	char	**map;

	start = start_map(matrix);
	size = size_map(matrix, start);
	max = search_max_len(matrix, start);
	map = ft_calloc(sizeof(char *), size + 3);
	map[0] = create_spaces(max);
	i = 1;
	while (i <= size)
	{
		map[i] = ft_specialdup(matrix[start], max);
		i++;
		start++;
	}
	map[i] = create_spaces(max);
	map[i + 1] = NULL;
	return (map);
}
