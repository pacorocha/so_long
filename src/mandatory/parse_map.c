#include "../../includes/mandatory/so_long.h"

static void parse_map_line(int len, char *line, t_data *my_data)
{
	int i;
	my_data->my_map.valid_chars = "01CPE";
	i = 0;
	while(i <= len)
	{
		if (!strchr(my_data->my_map.valid_chars, line[i]))
			print_error(4);
		if ((i == 0 || i == len) && line[i] != '1')
			print_error(3);
		i++;	
	}
}

void validate_lines(int l, char *line, t_data *my_data)
{
	static int ln_len;
	int len;

	len = 0;
	if (l == 1)
	{
		ln_len = ft_strlen(line);
		my_data->my_map.ln_len = ln_len;
	}
	if (l > 1)
	{
		len = ft_strlen(line);
		if (len != ln_len)
			print_error(1);
	}
	parse_map_line(len, line, my_data);
}
