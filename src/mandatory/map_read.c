/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 00:54:06 by jfrancis          #+#    #+#             */
/*   Updated: 2021/09/25 04:03:05 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/so_long.h"

static void	parse_map_line(int len, char *line, t_data *my_data)
{
	int	i;

	my_data->map.valid_chars = "01CPE";
	i = 0;
	while (i <= len)
	{
		if (!strchr(my_data->map.valid_chars, line[i]))
			print_error(2);
		if (line[i] == 'C')
			my_data->map.collectibles++;
		if (line[i] == 'E')
			my_data->map.exit++;
		if ((i == 0 && line[i] != '1') || (i == len - 1 && line[i] != '1'))
			print_error(3);
		if (line[i] == 'P')
			my_data->map.player++;
		i++;
	}
}

void	validate_lines(int l, char *line, t_data *my_data)
{
	int			len;

	len = 0;
	if (l == 1)
	{
		len = ft_strlen(line);
		my_data->line_length = len;
		my_data->map.width = len * 32;
	}
	if (l > 1)
	{
		len = ft_strlen(line);
		if (len != my_data->line_length)
			print_error(1);
	}
	parse_map_line(len, line, my_data);
}

void	validate_last_line(int len, char *line)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (line[i] != '1')
			print_error(3);
		i++;
	}
}
