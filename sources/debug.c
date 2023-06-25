/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:32:19 by thfirmin          #+#    #+#             */
/*   Updated: 2023/06/25 16:51:15 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*check_null(void *ptr)
{
	if (!ptr)
		return ("(nil)");
	else
		return ("");
}

// For debug, erase in future
void	print_map(t_map *map)
{
	int	i;

	printf ("\tt_map *map(%p){\n", map);
	printf ("\t\tint height = %d\n", map->height);
	printf ("\t\tint width = %d\n", map->width);
	printf ("\t\tchar **map =%s\n", check_null(map->map));
	i = -1;
	if (map->map)
		while (map->map[++i])
			printf("\t\t\t[%s]\n", map->map[i]);
	printf ("\t\tchar **texture =%s\n", check_null(map->texture));
	i = -1;
	if (map->texture)
		while (map->texture[++i])
			printf("\t\t\t[%s]\n", map->texture[i]);
	printf ("\t\tint **colors =%s\n", check_null(map->colors));
	i = -1;
	if (map->colors)
		while (map->colors[++i])
			printf("\t\t\t[%d, %d, %d]\n", map->colors[i][0], \
					map->colors[i][1], map->colors[i][2]);
	printf ("\t}\n");
}

// For debug, erase in future
void	print_mlx(t_mlx *mlx)
{
	printf ("\tt_mlx *mlx(%p){\n", mlx);
	printf ("\t\tvoid *init = [%p]\n", mlx->init);
	printf ("\t\tvoid *win = [%p]\n", mlx->win);
	printf ("\t\tvoid *img = [%p]\n", mlx->img);
	printf ("\t\tchar *addr = [%p]\n", mlx->addr);
	printf ("\t\tint bpp = [%i]\n", mlx->bpp);
	printf ("\t\tint line_len = [%i]\n", mlx->line_len);
	printf ("\t\tint endian = [%i]\n", mlx->endian);
	printf ("\t}\n");
}

// For debug, erase in future
void	print_ray(t_ray *ray)
{
	printf ("\tt_cub *ray(%p)\n", ray);
	printf ("\t\tdouble posx = [%f]\n", ray->posx);
	printf ("\t\tdouble posy = [%f]\n", ray->posy);
	printf ("\t\tdouble dirx = [%f]\n", ray->dirx);
	printf ("\t\tdouble diry = [%f]\n", ray->diry);
	printf ("\t\tdouble planex = [%f]\n", ray->planex);
	printf ("\t\tdouble planey = [%f]\n", ray->planey);
	printf ("\t\tdouble time = [%f]\n", ray->time);
	printf ("\t\tdouble old_time = [%f]\n", ray->old_time);
	printf ("\t\tdouble raydirx = [%f]\n", ray->raydirx);
	printf ("\t\tdouble raydiry = [%f]\n", ray->raydiry);
	printf ("\t\tdouble deltadistx = [%f]\n", ray->deltadistx);
	printf ("\t\tdouble deltadisty = [%f]\n", ray->deltadisty);
	printf ("\t\tdouble perpwalldist = [%f]\n", ray->perpwalldist);
	printf ("\t\tdouble distpx = [%f]\n", ray->distpx);
	printf ("\t\tdouble distpy = [%f]\n", ray->distpy);
	printf ("\t\tint stepx = [%d]\n", ray->stepx);
	printf ("\t\tint stepy = [%d]\n", ray->stepy);
	printf ("\t\tint mx = [%d]\n", ray->mx);
	printf ("\t\tint my = [%d]\n", ray->my);
	printf ("\t\tint hit = [%d]\n", ray->hit);
	printf ("\t\tint side = [%d]\n", ray->side);
	printf ("\t\tint d_start = [%d]\n", ray->d_start);
	printf ("\t\tint d_end = [%d]\n", ray->d_end);
	printf ("\t}\n");
}

// For debug, erase in future
void	print_cub(t_cube *cub)
{
	printf ("t_cub *cub(%p){\n", cub);
	print_map(&cub->world);
	print_mlx(&cub->mlx);
	print_ray(&cub->ray);
	printf ("}\n");
}
