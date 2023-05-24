/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:35:07 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/05/24 11:46:35 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_cube *cub)

{
	cub->d_mlx.init = mlx_init();
	cub->d_mlx.win = mlx_new_window(cub->d_mlx.init, 600, 600, "Minecasting");
	cub->d_mlx.img = mlx_new_image(cub->d_mlx.init, 600, 600);
	cub->d_mlx.addr = mlx_get_data_addr(cub->d_mlx.img, &cub->d_mlx.bpp, \
	&cub->d_mlx.line_len, &cub->d_mlx.endian);
	mlx_put_image_to_window(cub->d_mlx.init, cub->d_mlx.win, \
	cub->d_mlx.img, 0, 0);
	mlx_loop(cub->d_mlx.init);
}

int	main(int argc, char **argv)

{
	t_cube	cube;
	int		fd;

	fd = 0;
	if (argc == 2)
	{
		fd = error_menu(argv, argc);
		init_mlx(&cube);
		get_file(fd, &cube);
	}
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