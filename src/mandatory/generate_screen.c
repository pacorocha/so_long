#include "../../includes/mandatory/so_long.h"

void put_images(t_data *my_data)
{
	void	*img;
	char	*relative_path = "./images/mush_tree.xpm";
	int		img_width;
	int		img_height;
	int		i;
	int		l;
	int		map_len;

	img_width = 32;
	img_height = 32;
	map_len = ft_strlen(my_data->my_map.map_str);
	i = 0;
	l = 0;
	while (i <= map_len)
	{
		while (l < my_data->line_length)
		{
			img = mlx_xpm_file_to_image(my_data->my_mlx.mlx, relative_path, &img_width, &img_height);
			mlx_put_image_to_window(my_data->my_mlx.mlx, my_data->my_mlx.mlx_win, img, l * img_height + i, l * img_height + i);
			l++;
		}
		l = 1;
		i++;
	}
}
