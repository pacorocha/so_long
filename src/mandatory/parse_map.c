/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 01:28:14 by jfrancis          #+#    #+#             */
/*   Updated: 2021/09/25 03:32:30 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/so_long.h"

static void	check_elements(char *line, t_data *my_data)
{
	if (my_data->map.player != 1 || my_data->map.exit < 1
		|| my_data->map.collectibles < 1)
	{
		free(line);
		print_error(4);
	}
}

void	generate_map(int map_file, t_data *my_data)
{
	char	*line;
	char	*tmp_line;
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
	{
		validate_last_line(len, line);
		append_line(&tmp_line, line);
		free(line);
	}
	check_elements(tmp_line, my_data);
	my_data->map.height = l * 32;
	my_data->map.map_str = tmp_line;
}
