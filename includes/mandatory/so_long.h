#ifndef SO_LONG_H
# define SO_LONG_H
# define BLOCK_SIZE 32
# define KEY_ABNT_Q (0x71)
# define KEY_ABNT_A (0x61)
# define KEY_ABNT_S (0x73)
# define KEY_ABNT_D (0x64)
# define KEY_ABNT_W (0x77)
# define KEY_ESCAPE (0xff1b)

# include "../../libs/libft/libft.h"
# include "../../libs/minilibx-linux/mlx.h"
# include "../../libs/minilibx-linux/mlx_int.h"

typedef struct	s_square {
	int		id;
	int		x;
	int		y;
	char	c;
}				t_square;

typedef struct	s_map {
	int		width;
	int		height;
	int		player;
	int		player_pos;
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
	int			start;
	t_map		map;
	t_my_mlx	game;
}				t_data;

int		close_window(t_my_mlx *my_mlx);
int		key_press(int key_code, t_data *my_data);
void	validate_lines(int l, char *line, t_data *my_data);
void	print_green();
void	print_yellow();
void	print_white();
void	print_red ();
void	print_error(int id_error);
char	*check_error(int id_error);
int		start_map(t_data *my_data);
void	draw_square(t_data *my_data, int x, int y);
#endif
