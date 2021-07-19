#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../libs/libft/libft.h"
# include "../../libs/minilibx-linux/mlx.h"
# include "../../libs/minilibx-linux/mlx_int.h"

typedef struct s_my_mlx {
	void *mlx;
	void *mlx_win;
}				t_my_mlx;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int		close_window(t_my_mlx *my_mlx);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_square(t_data img, t_my_mlx *my_mlx);

#endif
