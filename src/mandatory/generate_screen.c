/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 00:39:26 by jfrancis          #+#    #+#             */
/*   Updated: 2021/09/23 03:45:49 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/so_long.h"

int	render_map(t_data *my_data)
{
	int		i;
	int		l;
	int		j;
	int		map_len;

	map_len = ft_strlen(my_data->map.map_str);
	i = 0;
	l = 0;
	j = 0;
	while (i < map_len)
	{
		while (j < my_data->line_length)
		{
			define_image(my_data->map.map_str[i], my_data);
			player_position(my_data, i);
			draw_square(my_data, j, l);
			i++;
			j++;
		}
		l++;
		j = 0;
	}
	return (0);
}
