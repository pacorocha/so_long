/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 04:12:15 by jfrancis          #+#    #+#             */
/*   Updated: 2021/09/25 04:12:17 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BLOCK_SIZE 32
# define HERO_IMG "images/hero.xpm"
# define GROUND_IMG "images/ground.xpm"
# define COLLECTIBLE_IMG "images/sheep.xpm"
# define WALL_IMG "images/mush_tree.xpm"
# define EXIT_IMG "images/exit.xpm"

# define KEY_ABNT_Q (0x71)
# define KEY_ABNT_A (0x61)
# define KEY_ABNT_S (0x73)
# define KEY_ABNT_D (0x64)
# define KEY_ABNT_W (0x77)
# define KEY_ESCAPE (0xff1b)

# include "../../libs/libft/libft.h"
# include "../../libs/minilibx-linux/mlx.h"
# include "../../libs/minilibx-linux/mlx_int.h"

typedef struct s_square {
	int		id;
	int		x;
	int		y;
	char	c;
}				t_square;

typedef struct s_map {
	int		width;
	int		height;
	int		player;
	int		player_pos;
	int		collectibles;
	int		exit;
	char	*map_str;
	char	*valid_chars;
	char	*img_path;
}				t_map;

typedef struct s_my_mlx {
	void	*mlx;
	void	*mlx_win;
}				t_my_mlx;

typedef struct s_data {
	void		*img;
	int			*addr;
	int			bpp;
	int			line_length;
	int			endian;
	int			moves;
	t_map		map;
	t_my_mlx	game;
}				t_data;

int		close_window(t_data *my_data);
int		key_press(int key_code, t_data *my_data);
void	validate_lines(int l, char *line, t_data *my_data);
void	validate_last_line(int len, char *line);
void	append_line(char **tmp_line, char *line);
void	generate_map(int map_file, t_data *my_data);
void	print_green(void);
void	print_yellow(void);
void	print_white(void);
void	print_red(void);
void	print_error(int id_error);
char	*check_error(int id_error);
int		render_map(t_data *my_data);
void	define_image(char c, t_data *my_data);
void	draw_square(t_data *my_data, int x, int y);
void	player_position(t_data *my_data, int i);
#endif
