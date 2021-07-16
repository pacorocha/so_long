#include "../../includes/mandatory/so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

static int	closew(t_my_mlx *my_mlx)
{
	mlx_destroy_window(my_mlx->mlx, my_mlx->mlx_win);
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_data img, t_my_mlx *my_mlx) {
	int		i;
	int		a;
	int		b;

	i = 25;
	a = 0;
	b = 0;
	while (i > 0)
	{
		my_mlx_pixel_put(&img, a+i, b, 0x00FF0000);
		my_mlx_pixel_put(&img, a, b+i, 0x00FF0000);
		i--;
	}
	a = 25;
	b = 25;
	i = 50;
	while (i > 25)
	{
		my_mlx_pixel_put(&img, a+i-(b*2), b, 0x00FF0000);
		my_mlx_pixel_put(&img, a, b+i-(a*2), 0x00FF0000);
		i--;
	}
	mlx_put_image_to_window(my_mlx->mlx, my_mlx->mlx_win, img.img, 15, 20);
}

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
	mlx_hook(my_mlx.mlx_win, 33, 1L << 17, closew, &my_mlx);
	mlx_loop(my_mlx.mlx);
}
