#include "../../includes/mandatory/so_long.h"

int	main(void)
{

	t_my_mlx my_mlx;
	t_data	img;

	my_mlx.mlx = mlx_init();
	my_mlx.mlx_win = mlx_new_window(my_mlx.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(my_mlx.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	draw_square(img, &my_mlx);
	mlx_hook(my_mlx.mlx_win, 33, 1L << 17, close_window, &my_mlx);
	mlx_loop(my_mlx.mlx);
}
