#include "../../includes/mandatory/so_long.h"

int	close_window(t_my_mlx *my_mlx)
{
	mlx_destroy_window(my_mlx->mlx, my_mlx->mlx_win);
	exit(0);
	return (0);
}
