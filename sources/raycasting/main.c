/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:35:07 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/06/25 16:35:33 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

// Don't miss to init textures atributes here
void	init_mlx(t_cube *cub)
{
	cub->mlx.init = mlx_init();
	cub->mlx.win = mlx_new_window(cub->mlx.init, 600, 600, "Minecasting");
	cub->mlx.img = mlx_new_image(cub->mlx.init, 600, 600);
	cub->mlx.addr = mlx_get_data_addr(cub->mlx.img, &cub->mlx.bpp, \
	&cub->mlx.line_len, &cub->mlx.endian);
}

// Begin of program
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
	mlx_loop_hook(cub.mlx.init, load_engine, &cub);
	mlx_loop(cub.mlx.init);
	return (0);
}
