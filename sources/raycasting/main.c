/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:35:07 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/05/29 17:13:35 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

	fd = error_menu(argv, argc);
	if (fd == -1)
		return (1);
	get_file(fd, &cub);
	init_mlx(&cub);
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