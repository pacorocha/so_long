#include "../../includes/mandatory/so_long.h"

static void	check_player(char *line, int i, t_data *my_data)
{
	if (line[i] == 'P')
		my_data->my_map.player++;
	if (my_data->my_map.player > 1)
		print_error(4);
}

static void	parse_map_line(int len, char *line, t_data *my_data)
{
	int	i;

	my_data->my_map.valid_chars = "01CPE";
	i = 0;
	while (i <= len)
	{
		if (!strchr(my_data->my_map.valid_chars, line[i]))
			print_error(2);
		if (line[i] == 'C')
			my_data->my_map.collectibles++;
		if (line[i] == 'E')
			my_data->my_map.exit++;
		if ((i == 0 && line[i] != '1') || (i == len - 1 && line[i] != '1'))
			print_error(3);
		check_player(line, i, my_data);
		i++;
	}
}

void	validate_lines(int l, char *line, t_data *my_data)
{
	static int	ln_len;
	int			len;

	len = 0;
	if (l == 1)
	{
		ln_len = ft_strlen(line);
		my_data->my_map.width = ln_len * 32;
	}
	if (l > 1)
	{
		len = ft_strlen(line);
		if (len != ln_len)
			print_error(1);
	}
	parse_map_line(len, line, my_data);
}
