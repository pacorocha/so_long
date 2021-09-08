#include "../../includes/mandatory/so_long.h"

static void define_image(char c, t_data *my_data)
{ 
	if (c == '1')
		my_data->my_map.img_path = "./images/mush_tree.xpm";
	else if (c == '0')
		my_data->my_map.img_path = "./images/ground.xpm";
	else if (c == 'C')
		my_data->my_map.img_path = "./images/sheep.xpm";
	else if (c == 'P')
		my_data->my_map.img_path = "./images/hero.xpm";
}

int	draw_map(t_data *my_data)
{
	int		img_size;
	int		i;
	int		l;
	int		j;
	int		map_len;

	map_len = ft_strlen(my_data->my_map.map_str);
	i = 0;
	l = 0;
	j= 0;
	while (i <= map_len)
	{
		while (j < my_data->line_length)
		{
			define_image(my_data->my_map.map_str[i], my_data);
			my_data->img = mlx_xpm_file_to_image(my_data->my_mlx.mlx, my_data->my_map.img_path, &img_size, &img_size);					
			mlx_put_image_to_window(my_data->my_mlx.mlx, my_data->my_mlx.mlx_win, my_data->img, j * img_size, l * img_size);
			i++;
			j++;
		}
		l++;
		j = 0;
	}
	return (0);
}
