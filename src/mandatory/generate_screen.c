/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 00:39:26 by jfrancis          #+#    #+#             */
/*   Updated: 2021/09/09 01:56:53 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/so_long.h"

static void	define_image(char c, t_data *my_data)
{
	if (c == '1')
		my_data->my_map.img_path = "./images/mush_tree.xpm";
	else if (c == '0')
		my_data->my_map.img_path = "./images/ground.xpm";
	else if (c == 'C')
		my_data->my_map.img_path = "./images/sheep.xpm";
	else if (c == 'P')
		my_data->my_map.img_path = "./images/hero.xpm";
	else if (c == 'E')
		my_data->my_map.img_path = "./images/exit.xpm";
}

int	draw_map(t_data *my_data)
{
	int		img_s;
	int		i;
	int		l;
	int		j;
	int		map_len;

	map_len = ft_strlen(my_data->my_map.map_str);
	i = 0;
	l = 0;
	j = 0;
	while (i <= map_len)
	{
		while (j < my_data->line_length)
		{
			if (my_data->my_map.map_str[i] == 'P')
			{
				my_data->my_map.player_x = j * img_s;
				my_data->my_map.player_y = l * img_s;
			}
			define_image(my_data->my_map.map_str[i], my_data);
			my_data->img = mlx_xpm_file_to_image(my_data->my_mlx.mlx,
				my_data->my_map.img_path, &img_s, &img_s);
			mlx_put_image_to_window(my_data->my_mlx.mlx,
				my_data->my_mlx.mlx_win, my_data->img, j * img_s, l * img_s);
			i++;
			j++;
		}
		l++;
		j = 0;
	}
	return (0);
}
