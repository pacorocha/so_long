#include "./includes/so_long.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, width, height, "Hello world!");
	mlx_loop(mlx);
}