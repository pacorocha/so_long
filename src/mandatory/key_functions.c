/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 01:46:44 by jfrancis          #+#    #+#             */
/*   Updated: 2021/09/19 23:38:22 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/so_long.h"

int	close_window(t_my_mlx *my_mlx)
{
	mlx_destroy_window(my_mlx->mlx, my_mlx->mlx_win);
	exit(0);
	return (0);
}

int key_press(int key_code, t_data *my_data)
{
	int y;
	int x;

	y = my_data->map.width / 32;
	x = my_data->map.height / 32;

	if (key_code == KEY_ESCAPE || key_code == KEY_ABNT_Q)
		close_window(&my_data->game);
	if (key_code == KEY_ABNT_W)
		my_data->map.player_y = my_data->map.player_y - 32;
	return (1);
}