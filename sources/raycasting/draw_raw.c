/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 02:03:12 by thfirmin          #+#    #+#             */
/*   Updated: 2023/05/17 20:57:44 by rmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parse.h"

#define COL 512
#define LIN 1024

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits;
	int		len_line;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len_line + x * (data->bits / 8));
	*(unsigned int*)dst = color;
}

