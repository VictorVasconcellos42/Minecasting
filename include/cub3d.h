/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 01:59:28 by thfirmin          #+#    #+#             */
/*   Updated: 2023/05/23 10:10:50 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

typedef enum e_texture
{
	NO = 0,
	SO,
	WE,
	EA
} t_texture;

# define F 0
# define C 1

# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"
# include "libgc.h"
# include "get_next_line.h"

typedef struct s_cube
{
	char	**map;
	char	**path;
	void	*init;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		test;
	char	**texture;
	char	**colors;
	char	*resolution;
	char	*sprites;
	char	**file;
}	t_cube;

void	draw_line(t_cube *cube, int x1, int x2, int y, int color);
void	draw_vline(t_cube *cube, int x, int y1, int y2, int color);
void	draw_cube(t_cube *cube, int x, int y, int color);
void	put_pixel(t_cube *cube, int x, int y, int color);

#endif
