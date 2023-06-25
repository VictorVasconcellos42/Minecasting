/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:35:07 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/06/23 14:26:48 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_map *map)
{
	printf ("\tt_map *map(%p){\n", map);
	printf ("\t\tint height = %d\n", map->height);
	printf ("\t\tint width = %d\n", map->width);
	printf ("\t\tchar **map =%s\n", map->map ? "" : " (nil)");
	if (map->map)
		for(int i = 0; map->map[i]; i ++)
			printf("\t\t\t[%s]\n", map->map[i]);
	printf ("\t\tchar **texture =%s\n", map->texture ? "" : " (nil)");
	if (map->texture)
		for(int i = 0; map->texture[i]; i ++)
			printf("\t\t\t[%s]\n", map->texture[i]);
	printf ("\t\tint **colors =%s\n", map->colors ? "" : " (nil)");
	if (map->colors)
		for(int i = 0; map->colors[i]; i ++)
				printf("\t\t\t[%d, %d, %d]\n", map->colors[i][0], map->colors[i][1], map->colors[i][2]);
	printf ("\t}\n");
}

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

void	print_cub(t_cube *cub)
{
	printf ("t_cub *cub(%p){\n", cub);
	print_map(&cub->world);
	print_mlx(&cub->mlx);
	print_ray(&cub->ray);
	printf ("}\n");
}

void	init_mlx(t_cube *cub)

{
	cub->mlx.init = mlx_init();
	cub->mlx.win = mlx_new_window(cub->mlx.init, 600, 600, "Minecasting");
	cub->mlx.img = mlx_new_image(cub->mlx.init, 600, 600);
	cub->mlx.addr = mlx_get_data_addr(cub->mlx.img, &cub->mlx.bpp, \
	&cub->mlx.line_len, &cub->mlx.endian);
}

int	main(int argc, char **argv)
{
	t_cube	cub;
	int		fd;

	ft_bzero(&cub, sizeof(t_cube));
	fd = error_menu(argv, argc);
	get_file(fd, &cub);
	print_map(&cub.world);
	init_mlx(&cub);
	init_hooks(&cub);
	integration(&cub);
	load_engine(&cub);
	mlx_loop(cub.mlx.init);
	return (0);
}


/*


	1 - Validação do arquivo e dos dados
	2 - Normalização dos dados e preechimento de dados nas estruturas
	3 - Inicialização da mlx
	4 - Eventos de movimentação - mlx hook
	5 - Eventos de Janela - mlx hook
	6 - Inicialização dos dados do player
	7 - Carregar as texturas
	8 - Vizualização inical do player
	9 - Troca de pixel de textura.
*/

