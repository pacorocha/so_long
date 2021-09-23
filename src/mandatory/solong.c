/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 01:48:41 by jfrancis          #+#    #+#             */
/*   Updated: 2021/09/23 19:17:45 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/so_long.h"

static void	check_file_ext(const char *filename)
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
	my_data->moves = 0;
}

void append_line(char **tmp_line, char *line)
{
	char *appended_line;

	appended_line = *tmp_line;
	*tmp_line = ft_strjoin(*tmp_line, line);
	free(appended_line);
}

void	generate_map(int map_file, t_data *my_data)
{
	char	*line;
	char	*tmp_line;
	// char	*map_line;
	int		l;
	int		len;

	l = 1;
	tmp_line = ft_strdup("");
	while (get_next_line(map_file, &line) == 1)
	{
		validate_lines(l, line, my_data);
		append_line(&tmp_line, line);
		free(line);
		l++;
	}
	len = ft_strlen(line);
	if (len != my_data->line_length)
		print_error(1);
	else
		append_line(&tmp_line, line);
	my_data->map.height = l * 32;
	my_data->map.map_str = tmp_line;
	free(line);
}

void	validate_map(const char *filename, t_data *my_data)
{
	int		opened_map;

	check_file_ext(filename);
	opened_map = open(filename, O_RDONLY);
	if (opened_map < 0)
		perror("Error");
	else
	{
		init_params(my_data);
		generate_map(opened_map, my_data);
		close(opened_map);
	}
}

int	main(int argc, char **argv)
{
	const char	*filename;
	t_data		my_data;

	if (argc < 2)
		print_error(5);
	else if (argc > 2)
		print_error(6);
	else
		filename = argv[1];
	validate_map(filename, &my_data);
	my_data.game.mlx = mlx_init();
	my_data.game.mlx_win = mlx_new_window(my_data.game.mlx, my_data.map.width,
			my_data.map.height, "So long");
	mlx_hook(my_data.game.mlx_win, 33, 1L << 17, close_window, &my_data);
	mlx_key_hook(my_data.game.mlx_win, &key_press, &my_data);
	render_map(&my_data);
	mlx_loop(my_data.game.mlx);
	free(&my_data);
}
