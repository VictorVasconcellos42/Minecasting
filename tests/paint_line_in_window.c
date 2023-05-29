/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_line_in_window.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 07:36:13 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/05/24 11:53:34 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* void    open_window(t_cube *cube, char **argv)

{
    cube->init = mlx_init();
	cube->win = mlx_new_window(cube->init, atoi(argv[1]), atoi(argv[2]), argv[0]);
	cube->img = mlx_new_image(cube->init, atoi(argv[1]), atoi(argv[2]));
	cube->addr = mlx_get_data_addr(cube->img, &cube->bpp, &cube->line_len, &cube->endian);
}
 */
/* int main(int argc, char **argv)

{
    t_cube cube;
    int x[2];
    int y[2];

    x[0] = 0;
    y[0] = 0;
    x[1] = 500;
    y[1] = 500;
    if (argc < 3)
        return (1);
    open_window(&cube, argv);
    draw_line(&cube, x, y, 0x0000FF00);
    draw_vline(&cube, x, y, 0x0000FF00);
    draw_line(&cube, x, y, 0x0000FF00);
    draw_vline(&cube, x, y, 0x0000FF00);
    mlx_put_image_to_window(cube.init, cube.win, cube.img, 0, 0);
    mlx_loop(cube.init);
} */