/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:19:24 by jsantann          #+#    #+#             */
/*   Updated: 2023/06/23 14:42:05 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "cub3d.h"

typedef struct s_cube	t_cube;

int		**colorstrtoint(char **colors);
int		count_char(char *src, char key);
int		count_comma(char *str, int position);
int		count_matrix(char **matrix);
int		count_n(char *src, int start);
int		count_space(char *src);
int		count_str(char *src, char *key);
int		error_argc(int argc);
int		error_filename(char *argv);
int		error_menu(char **argv, int argc);
int		error_permission(char *argv);
int		get_r(char *str, int *position);
int		get_g(char *str, int *position);
int		get_b(char *str, int position);
int		locate_char(char *src, int start, char key);
int		search_max_len(char **matrix, int start);
int		size_map(char **matrix, int start);
int		start_map(char **matrix);
void	color_error(int i, int j);
void	color_rgb(int **colors);
void	color_validation(int **colors);
void	free_matrix(char **matrix);
void	print_matrix(char **matrix);
int		search_max_len(char **matrix, int start);
char	*create_spaces(int len);
char	*ft_specialdup(const char *s1, size_t len);
char	**get_map(char **matrix);
char	**get_texture_map(char **matrix);
char	**get_colors(char **matrix);
char	*get_resolution(char **matrix);
char	*get_sprite(char **matrix);
char	*create_vector(char *src, int start, int size);
char	*get_north(char **matrix);
char	*get_south(char **matrix);
char	*get_east(char **matrix);
char	*get_west(char **matrix);
char	*get_ceiling(char **matrix);
char	*get_floor(char **matrix);
void	get_file(int fd, t_cube *cube);
void	texture_null(char **texture);
void	texture_path(char **texture);
void	texture_validation(char **texture);
void	texture_little(char **texture);
void	texture_xpm(char **texture);
void	texture_exit(char **texture);
#endif
