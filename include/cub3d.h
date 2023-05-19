/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 01:59:28 by thfirmin          #+#    #+#             */
/*   Updated: 2023/05/19 16:08:00 by jsantann         ###   ########.fr       */
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
# include "get_next_line.h"

typedef struct s_cube
{
	char	**map;
	char	**texture;
	char	**colors;
	char	*resolution;
	char	*sprites;
	char	**file;
}	t_cube;

#endif
