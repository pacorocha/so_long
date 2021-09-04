#include "../../includes/mandatory/so_long.h"

static void	validate_file(const char *filename)
{
	char	*ext;

	ext = strrchr(filename, '.');
	if (ft_strncmp(ext + 1, "ber", 3) != 0)
		print_error(0);
}

static void	init_params(t_data *my_data)
{
	my_data->my_map.width = 0;
	my_data->my_map.height = 0;
	my_data->my_map.player = 0;
	my_data->my_map.collectibles = 0;
	my_data->my_map.exit = 0;
}

void	so_long(const char *filename, t_data *my_data)
{
	int		opened_map;
	char	*line;
	char	*tmp_line;
	int		l;
	int		len;

	validate_file(filename);
	opened_map = open(filename, O_RDONLY);
	l = 1;
	tmp_line = "";
	if (opened_map < 0)
		perror("Error");
	else
	{
		init_params(my_data);
		while (get_next_line(opened_map, &line) == 1)
		{
			validate_lines(l, line, my_data);
			tmp_line = ft_strjoin(tmp_line, line);
			l++;
		}
		len = ft_strlen(line);
		if (len != my_data->line_length)
			print_error(1);
		else
			tmp_line = ft_strjoin(tmp_line, line);
		my_data->my_map.height = l * 32;
		my_data->my_map.map_str = tmp_line;
		close(opened_map);
	}
}

int	main(void)
{
	const char	*filename = "map.ber";
	t_data		my_data;

	so_long(filename, &my_data);

	my_data.my_mlx.mlx = mlx_init();
	my_data.my_mlx.mlx_win = mlx_new_window(my_data.my_mlx.mlx, my_data.my_map.width, my_data.my_map.height, "So long");
	put_images(&my_data);
	mlx_hook(my_data.my_mlx.mlx_win, 33, 1L << 17, close_window, &my_data.my_mlx);
	mlx_loop(my_data.my_mlx.mlx);
	free(&my_data);
}
