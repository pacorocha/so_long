/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 01:46:44 by jfrancis          #+#    #+#             */
/*   Updated: 2021/09/24 00:42:44 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/so_long.h"

int	close_window(t_data *my_data)
{
	mlx_destroy_window(my_data->game.mlx, my_data->game.mlx_win);
	mlx_destroy_display(my_data->game.mlx);
	free(my_data->map.map_str);
	free(my_data->game.mlx);
	printf("estou aqui\n");
	exit(0);
	return (0);
}

void	move_player(int prev_pos, int next_pos, t_data *my_data)
{
	my_data->map.player_pos = next_pos;
	my_data->map.map_str[prev_pos] = '0';
	my_data->map.map_str[next_pos] = 'P';
	printf("moves: %i\n", my_data->moves);
}

int	define_key(int key_code, int dest_pos, t_data *my_data)
{
	if (key_code == KEY_ESCAPE || key_code == KEY_ABNT_Q)
		close_window(my_data);
	if (key_code == KEY_ABNT_W)
		dest_pos = my_data->map.player_pos - my_data->line_length;
	if (key_code == KEY_ABNT_S)
		dest_pos = my_data->map.player_pos + my_data->line_length;
	if (key_code == KEY_ABNT_A)
		dest_pos = my_data->map.player_pos - 1;
	if (key_code == KEY_ABNT_D)
		dest_pos = my_data->map.player_pos + 1;
	return (dest_pos);
}

int	activate_exit(int dest_pos, int next_pos, int prev_pos, t_data *my_data)
{
	if (my_data->map.map_str[dest_pos] == 'E' && my_data->map.collectibles == 0)
	{
		printf("you win!");
		my_data->moves++;
		next_pos = dest_pos;
		close_window(my_data);
	}	
	else
		next_pos = prev_pos;
	return (next_pos);
}

int	key_press(int key_code, t_data *my_data)
{
	int	prev_pos;
	int	next_pos;
	int	dest_pos;

	dest_pos = 0;
	prev_pos = my_data->map.player_pos;
	next_pos = my_data->map.player_pos;
	dest_pos = define_key(key_code, dest_pos, my_data);
	next_pos = activate_exit(dest_pos, next_pos, prev_pos, my_data);
	if (my_data->map.map_str[dest_pos] != '1'
		&& my_data->map.map_str[dest_pos] != 'E')
	{
		if (my_data->map.map_str[dest_pos] == 'C')
			my_data->map.collectibles--;
		next_pos = dest_pos;
		my_data->moves++;
	}
	move_player(prev_pos, next_pos, my_data);
	render_map(my_data);
	return (1);
}
