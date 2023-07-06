/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 01:59:28 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/06 15:41:56 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define F 0
# define C 1
# define TRUE 1
# define FALSE 0
# define SCREEN_W 600
# define SCREEN_H 600

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

enum e_events
{
	ON_KEY_DOWN = 2,
	ON_KEY_UP = 3,
	ON_BUTTON_DOWN = 4,
	ON_BUTTON_UP = 5,
	ON_MOUSE_NOTIFY = 6,
	ON_ENTER_NOTIFY = 7,
	ON_LEAVE_NOTIFY = 8,
	ON_FOCUS_IN = 9,
	ON_FOCUS_OUT = 10,
	ON_KEYMAP_NOTIFY = 11,
	ON_EXPOSE = 12,
	ON_GRAPHICS_EXPOSE = 13,
	ON_NO_EXPOSE = 14,
	ON_VISIBILITY_NOTIFY = 15,
	ON_CREATE_NOTIFY = 16,
	ON_DESTROY_WINDOW = 17,
	ON_UNMAP_NOTIFY = 18,
	ON_MAP_NOTIFY = 19,
	ON_MAP_REQUEST = 20,
	ON_REPARENT_NOTIFY = 21,
	ON_CONFIGURE_NOTIFY = 22,
	ON_CONFIGURE_REQUEST = 23,
	ON_GRAVITY_NOTIFY = 24,
	ON_RESIZE_REQUEST = 25,
	ON_CIRCULATE_NOTIFY = 26,
	ON_CIRCULATE_REQUEST = 27,
	ON_PROPERTY_NOTIFY = 28,
	ON_SELECTION_CLEAR = 29,
	ON_SELECTION_REQUEST = 30,
	ON_SELECTION_NOTIFY = 31,
	ON_COLORMAP_NOTIFY = 32,
	ON_CLIENT_MESSAGE = 33,
	ON_MAPPING_NOTIFY = 34,
	ON_GENERIC_EVENT = 35,
	ON_LAST_EVENT = 36
};

enum e_masks
{
	IN_NO_EVENT = 0,
	IN_KEY_DOWN = (1L << 0),
	IN_KEY_UP = (1L << 1),
	IN_BUTTON_DOWN = (1L << 2),
	IN_BUTTON_UP = (1L << 3),
	IN_ENTER_WINDOW = (1L << 4),
	IN_LEAVE_WINDOW = (1L << 5),
	IN_POINTER_MOUSE = (1L << 6),
	IN_POINTER_MOUSE_HINT = (1L << 7),
	IN_BUTTON1_MOUSE = (1L << 8),
	IN_BUTTON2_MOUSE = (1L << 9),
	IN_BUTTON3_MOUSE = (1L << 10),
	IN_BUTTON4_MOUSE = (1L << 11),
	IN_BUTTON5_MOUSE = (1L << 12),
	IN_BUTTON_MOUSE = (1L << 13),
	IN_KEYMAP_STATE = (1L << 14),
	IN_EXPOSURE = (1L << 15),
	IN_VISIBILITY_CHANGE = (1L << 16),
	IN_STRUCTURE_NOTIFY = (1L << 17),
	IN_RESIZE_REDIRECT = (1L << 18),
	IN_SUBSTRUCTURE_NOTIFY = (1L << 19),
	IN_SUBSTRUCTURE_REDIRECT = (1L << 20),
	IN_FOCUS_CHANGE = (1L << 21),
	IN_PROPERTY_CHANGE = (1L << 22),
	IN_COLORMAP_CHANGE = (1L << 23),
	IN_OWNER_GRAB_BUTTON = (1L << 24)
};

enum e_keymap
{
	KEY_ESC = 65307,
	KEY_ENTER = 65293,
	KEY_ALT = 65513,
	KEY_ALT_GR = 65027,
	KEY_TAB = 65298,
	KEY_CAPS_LOCK = 65509,
	KEY_LSHIFT = 65505,
	KEY_RSHIFT = 65506,
	KEY_BACKSPACE = 65288,
	KEY_CTRL = 65507,
	KEY_SPACE = 32,
	KEY_A = 97,
	KEY_B = 98,
	KEY_C = 99,
	KEY_D = 100,
	KEY_E = 101,
	KEY_F = 102,
	KEY_G = 103,
	KEY_H = 104,
	KEY_I = 105,
	KEY_J = 106,
	KEY_K = 107,
	KEY_L = 108,
	KEY_M = 109,
	KEY_N = 110,
	KEY_O = 111,
	KEY_P = 112,
	KEY_Q = 113,
	KEY_R = 114,
	KEY_S = 115,
	KEY_T = 116,
	KEY_U = 117,
	KEY_V = 118,
	KEY_W = 119,
	KEY_X = 120,
	KEY_Y = 121,
	KEY_Z = 122,
	KEY_QUOTE = 39,
	KEY_1 = 49,
	KEY_2 = 50,
	KEY_3 = 51,
	KEY_4 = 52,
	KEY_5 = 53,
	KEY_6 = 54,
	KEY_7 = 55,
	KEY_8 = 56,
	KEY_9 = 57,
	KEY_0 = 48,
	KEY_MINUS = 45,
	KEY_PLUS = 61,
	KEY_COMMA = 44,
	KEY_DOT = 46,
	KEY_SEMICOLON = 59,
	KEY_CDILLA = 231,
	KEY_TIL = 65107,
	KEY_RSQR_BRACKET = 93,
	KEY_ACCENT = 65105,
	KEY_LSQR_BRACKET = 91,
	KEY_SLASH = 47,
	KEY_BSLASH = 92,
	KEY_ARR_UP = 65362,
	KEY_ARR_DWN = 65364,
	KEY_ARR_LEFT = 65361,
	KEY_ARR_RIGHT = 65363
};

typedef struct s_color
{
	unsigned long	r;
	unsigned long	g;
	unsigned long	b;
}	t_color;

typedef struct s_ray
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;

	double	r_spd;
	double	m_spd;

	double	time;
	double	old_time;

	double	raydirx;
	double	raydiry;

	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	double	distpx;
	double	distpy;
	double	rad90;

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
	int		height;
	int		width;
	char	**texture;
	int		**colors;
}	t_map;

typedef struct s_text
{
	void	*addr;
	char	*head;
	int		bpp;
	int		slen;
	int		end;
	int		width;
	int		height;
}			t_text;

typedef struct s_cube
{
	t_map	world;
	t_text	**text;
	t_mlx	mlx;
	t_ray	ray;
}	t_cube;

void	draw_line(t_cube *cube, int *x, int *y, int color);
void	draw_vline(t_cube *cube, int x, t_text *texture);
void	draw_cube(t_cube *cube, int ceil, int floor);
void	put_pixel(t_cube *cube, int x, int y, int color);
void	integration(t_cube *cub);
void	show_data_integration(t_ray *ray);
int		rgb_to_color(char r, char g, char b);

void	init_texture(t_cube *cub, char **files);
t_text	*textnew(void *addr, int width, int height);

// HOOKS //
void	init_hooks(t_cube *cub);
int		keymap_press_control(int key, void *param);
int		keymap_release_control(int key, void *param);
int		the_end(void *param);

// MOVIMENT //
void	moviment_engine(t_cube *cub, int key);
void	look_engine(t_cube *cub, int key, double *dirx, double *diry);

// TEMP //
void	print_ray(t_ray *ray);
void	print_mlx(t_mlx *mlx);
void	print_map(t_map *map);
void	print_cub(t_cube *cub);

#endif
