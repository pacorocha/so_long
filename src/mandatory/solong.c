#include "../../includes/mandatory/so_long.h"

void so_long(const char *filename)
{
   int map;
   
   map = open(filename, O_RDONLY);
   if(map > 0)
   {
      printf("%s: opened\n", filename);
      close(map);
      printf("%s: closed\n", filename);
   }
   else
   {
      perror(filename);
   }
}

int	main(void)
{
	const char *filename = "map.ber";
	so_long(filename);
	return(0);
	/* t_my_mlx my_mlx;
	void	*img;
	char	*relative_path = "./images/ground.xpm";
	int		img_width;
	int		img_height;

	my_mlx.mlx = mlx_init();
	img_width = 32;
	img_height = 32;
	img = mlx_xpm_file_to_image(my_mlx.mlx, relative_path, &img_width, &img_height);
	my_mlx.mlx_win = mlx_new_window(my_mlx.mlx, 1920, 1080, "Hello world!");
	mlx_put_image_to_window(my_mlx.mlx, my_mlx.mlx_win, &img, 200, 200);
	mlx_hook(my_mlx.mlx_win, 33, 1L << 17, close_window, &my_mlx);
	mlx_loop(my_mlx.mlx); */
}
