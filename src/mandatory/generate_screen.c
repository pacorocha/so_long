/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 00:39:26 by jfrancis          #+#    #+#             */
/*   Updated: 2021/09/20 03:36:42 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/so_long.h"

static void	define_image(char c, t_data *my_data)
{
	int		img_s;

	if (c == '1')
		my_data->map.img_path = "./images/mush_tree.xpm";
	else if (c == '0')
		my_data->map.img_path = "./images/ground.xpm";
	else if (c == 'C')
		my_data->map.img_path = "./images/sheep.xpm";
	else if (c == 'P')
		my_data->map.img_path = "./images/hero.xpm";
	else if (c == 'E')
		my_data->map.img_path = "./images/exit.xpm";
	my_data->img = mlx_xpm_file_to_image(my_data->game.mlx,
			my_data->map.img_path, &img_s, &img_s);
}

static void	player_start(t_data *my_data, int i, int j, int l)
{
	if (my_data->map.map_str[i] == 'P' && my_data->start == 1)
	{
		my_data->map.player_x = j * BLOCK_SIZE;
		my_data->map.player_y = l * BLOCK_SIZE;
		my_data->map.player_pos = i;
		my_data->start = 0;
	}
}

int	start_map(t_data *my_data)
{
	int		i;
	int		l;
	int		j;
	int		map_len;

	map_len = ft_strlen(my_data->map.map_str);
	i = 0;
	l = 0;
	j = 0;
	while (i <= map_len)
	{
		while (j < my_data->line_length)
		{
			define_image(my_data->map.map_str[i], my_data);
			player_start(my_data, i, j, l);
			draw_square(my_data, j, l);
			i++;
			j++;
		}
		l++;
		j = 0;
	}
	return (0);
}
