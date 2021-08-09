#include "../../includes/mandatory/so_long.h"

void so_long(const char *filename, t_data *my_data)
{
	int opened_map;
	char *line;
	char *tmp_line;
	int l;

	opened_map = open(filename, O_RDONLY);
	l = 1;
	tmp_line = "";
	if (opened_map < 0)
		perror("Error");
	else
	{
		while (get_next_line(opened_map, &line) == 1)
		{
			validate_lines(l, line, my_data);
			tmp_line = ft_strjoin(tmp_line, line);
			l++;
		}
		if (my_data->my_map.ln_len == l)
			print_error(2);
		my_data->my_map.ln_nbr = l;
		my_data->my_map.map_str = tmp_line;
		close(opened_map);
	}
}

int	main(void)
{
	const char *filename = "map.ber";
	t_data my_data;
	so_long(filename, &my_data);
	return(0);

	/* void	*img;
	char	*relative_path = "./images/ground.xpm";
	int		img_width;
	int		img_height;

	my_mlx.mlx = mlx_init();
	img_width = 32;
	img_height = 32;
	img = mlx_xpm_file_to_image(my_mlx.mlx, relative_path, &img_width, &img_height);
	my_mlx.mlx_win = mlx_new_window(my_mlx.mlx, l * 32, 1080, "Hello world!");
	mlx_put_image_to_window(my_mlx.mlx, my_mlx.mlx_win, &img, 200, 200);
	mlx_hook(my_mlx.mlx_win, 33, 1L << 17, close_window, &my_mlx);
	mlx_loop(my_mlx.mlx); */
}
