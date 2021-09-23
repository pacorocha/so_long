/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 01:28:14 by jfrancis          #+#    #+#             */
/*   Updated: 2021/09/24 00:12:57 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/so_long.h"

static void	check_player(char *line, int i, t_data *my_data)
{
	if (line[i] == 'P')
		my_data->map.player++;
	if (my_data->map.player > 1)
		print_error(4);
}

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
		check_player(line, i, my_data);
		i++;
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
		append_line(&tmp_line, line);
	my_data->map.height = l * 32;
	my_data->map.map_str = tmp_line;
	free(line);
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
