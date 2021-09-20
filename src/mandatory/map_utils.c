/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:56:30 by jfrancis          #+#    #+#             */
/*   Updated: 2021/09/20 00:02:59 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/so_long.h"

void	draw_square(t_data *my_data, int x, int y)
{
	mlx_put_image_to_window(my_data->game.mlx, my_data->game.mlx_win,
		my_data->img, x * BLOCK_SIZE, y * BLOCK_SIZE);
}
