#include "../../includes/mandatory/so_long.h"

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
