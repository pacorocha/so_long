#ifndef SO_LONG_H
# define SO_LONG_H
# define BLOCK_SIZE 32

# include "../../libs/libft/libft.h"
# include "../../libs/minilibx-linux/mlx.h"
# include "../../libs/minilibx-linux/mlx_int.h"

typedef struct	s_map {
	int		width;
	int		height;
	int		player;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		exit;
	char	*map_str;
	char	*valid_chars;
	char	*img_path;
}				t_map;

typedef struct s_my_mlx {
	void *mlx;
	void *mlx_win;
}				t_my_mlx;

typedef struct	s_data {
	void		*img;
	int			*addr;
	int			bpp;
	int			line_length;
	int			endian;
	t_map		my_map;
	t_my_mlx	my_mlx;
}				t_data;

int		close_window(t_my_mlx *my_mlx);
void	validate_lines(int l, char *line, t_data *my_data);
void	print_green();
void	print_yellow();
void	print_white();
void	print_red ();
void	print_error(int id_error);
char	*check_error(int id_error);
int		draw_map(t_data *my_data);
#endif
