/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 01:48:41 by jfrancis          #+#    #+#             */
/*   Updated: 2021/09/20 03:35:02 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	my_data->map.width = 0;
	my_data->map.height = 0;
	my_data->map.player = 0;
	my_data->map.collectibles = 0;
	my_data->map.exit = 0;
	my_data->start = 1;
}

void	validate_map(const char *filename, t_data *my_data)
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
		my_data->map.height = l * 32;
		my_data->map.map_str = tmp_line;
		close(opened_map);
	}
}

int	main(void)
{
	const char	*filename = "map2.ber";
	t_data		my_data;

	validate_map(filename, &my_data);

	my_data.game.mlx = mlx_init();
	my_data.game.mlx_win = mlx_new_window(my_data.game.mlx, my_data.map.width, my_data.map.height, "So long");
	mlx_hook(my_data.game.mlx_win, 33, 1L << 17, close_window, &my_data.game);
	mlx_key_hook(my_data.game.mlx_win, &key_press, &my_data.game);
	start_map(&my_data);
	mlx_loop(my_data.game.mlx);
	free(&my_data);
}
