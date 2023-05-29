/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 01:59:28 by thfirmin          #+#    #+#             */
/*   Updated: 2023/05/29 20:03:43 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"
# include "parse.h"
# include "get_next_line.h"
# include "raycasting.h"

typedef enum e_texture
{
	NO = 0,
	SO,
	WE,
	EA
}	t_texture;

# define F 0
# define C 1
# define SCREEN_W 600
# define SCREEN_H 600

typedef struct s_cube	t_cube;

typedef struct s_color
{
	unsigned long	color_r;
	unsigned long	color_g;
	unsigned long	color_b;
}	t_color;

typedef struct s_ray
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;

	double	time;
	double	old_time;

	double	raydirx;
	double	raydiry;

	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	double	distpx;
	double	distpy;

	int		stepx;
	int		stepy;
	int		mx;
	int		my;
	int		hit;
	int		side;
	int		d_start;
	int		d_end;
}	t_ray;

typedef struct s_mlx
{
	void	*init;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_mlx;

typedef struct s_map
{
	char	**map;
	char	**texture;
	char	**colors;
	char	*resolution;
	char	*sprites;
	char	**file;
}	t_map;

typedef struct s_cube
{
	t_map	world;
	t_mlx	mlx;
	t_ray	ray;
}	t_cube;

void	draw_line(t_cube *cube, int *x, int *y, int color);
void	draw_vline(t_cube *cube, int x, int color);
void	draw_cube(t_cube *cube, int x, int y, int color);
void	put_pixel(t_cube *cube, int x, int y, int color);

#endif
