/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:56:30 by jfrancis          #+#    #+#             */
/*   Updated: 2021/09/24 00:10:06 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/so_long.h"

void	player_position(t_data *my_data, int i)
{
	if (my_data->map.map_str[i] == 'P')
		my_data->map.player_pos = i;
}

void	define_image(char c, t_data *my_data)
{
	int		img_s;

	if (c == '1')
		my_data->map.img_path = WALL_IMG;
	else if (c == '0')
		my_data->map.img_path = GROUND_IMG;
	else if (c == 'C')
		my_data->map.img_path = COLLECTIBLE_IMG;
	else if (c == 'P')
		my_data->map.img_path = HERO_IMG;
	else if (c == 'E')
		my_data->map.img_path = EXIT_IMG;
	my_data->img = mlx_xpm_file_to_image(my_data->game.mlx,
			my_data->map.img_path, &img_s, &img_s);
}

void	draw_square(t_data *my_data, int x, int y)
{
	mlx_put_image_to_window(my_data->game.mlx, my_data->game.mlx_win,
		my_data->img, x * BLOCK_SIZE, y * BLOCK_SIZE);
	mlx_destroy_image(my_data->game.mlx, my_data->img);
}
