
#include "parse.h"

int	main(int argc, char **argv)
{
//	int	fd;

//	fd = ierror_menu(argv, argc);
	void	*mlx;
	void	*mlx_win;
	(void)argc;
	(void)argv;
	t_data	img;
	int	line = 0;
	int	col = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, LIN, COL, "cube3D");
	img.img = mlx_new_image(mlx, LIN, COL);
	img.addr = mlx_get_data_addr(img.img, &img.bits, &img.len_line, &img.endian);
	while (line < LIN)
	{
		while (col < COL / 2)
		{
			my_mlx_pixel_put(&img, line, col, 0x00666666);
			col++;
		}
		col = 0;
		mlx_put_image_to_window(mlx, mlx_win, img.img, line, col);
		line++;
	}
	line = 0;
	while (line < LIN)
	{
		while (col < COL)
		{
			my_mlx_pixel_put(&img, line, col, 0x00999999);
			col++;
		}
		col = COL / 2;
		mlx_put_image_to_window(mlx, mlx_win, img.img, line, col);
		line++;
	}


	line = 0;
	col = 0;
	while (col <= COL)
	{
		draw_line(mlx, mlx_win, 0, col, LIN, col);
		col = col + 128;
	}
