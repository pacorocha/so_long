NAME = solong
LIBFT = libft.a
MLX = libmlx.a

LIBFT_PATH = ./libs/libft/
MLX_PATH = ./libs/minilibx-linux/

SRC = ./src/mandatory/
PARSE = $(SRC)parse_scene/
RENDER = $(SRC)render_cub/
SYSTEM = $(SRC)system/

SRC_BONUS = ./src/bonus/
PARSE_BONUS = $(SRC_BONUS)parse_scene/
RENDER_BONUS = $(SRC_BONUS)render_cub/
SYSTEM_BONUS = $(SRC_BONUS)system/

FILES = $(SRC)solong.c
OBJECTS = solong.o

BONUS_FILES = $(SRC_BONUS)cub_b.c $(SYSTEM_BONUS)free_b.c $(SYSTEM_BONUS)save_bmp_b.c $(SYSTEM_BONUS)events_b.c $(SYSTEM_BONUS)error_b.c $(PARSE_BONUS)parse_scene_b.c $(PARSE_BONUS)parse_settings_b.c $(PARSE_BONUS)parse_map_b.c $(PARSE_BONUS)check_map_b.c $(PARSE_BONUS)load_textures_b.c $(RENDER_BONUS)render_cub_b.c $(RENDER_BONUS)render_tools_b.c $(RENDER_BONUS)put_line_b.c $(RENDER_BONUS)render_minimap_b.c $(RENDER_BONUS)put_background_b.c $(RENDER_BONUS)put_hud_b.c $(RENDER_BONUS)render_utils_b.c $(RENDER_BONUS)raycasting_b.c $(RENDER_BONUS)collisions_b.c $(RENDER_BONUS)put_walls_b.c $(RENDER_BONUS)put_sprites_b.c $(RENDER_BONUS)background_gradient_b.c $(RENDER_BONUS)night_vision_b.c $(RENDER_BONUS)wall_color_b.c $(RENDER_BONUS)check_tile_b.c
BONUS_OBJECTS = cub_b.o free_b.o error_b.o parse_settings_b.o parse_map_b.o check_map_b.o render_cub_b.o events_b.o render_tools_b.o put_line_b.o render_minimap_b.o put_background_b.o render_utils_b.o raycasting_b.o put_walls_b.o save_bmp_b.o load_textures_b.o put_sprites_b.o collisions_b.o parse_scene_b.o background_gradient_b.o night_vision_b.o put_hud_b.o wall_color_b.o check_tile_b.o

CC = clang
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lm -lbsd -lmlx -lXext -lX11
RE = rm -f

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) $(MLX)
	@echo -ne 'making so long: #####                     (33%)\r'
	@sleep 1
	@echo -ne 'making so long: #############             (66%)\r'
	@sleep 1
	@echo -ne 'making so long: ##########################(100%)\r'
	@echo -ne '\n'
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -L $(LIBFT_PATH) -L $(MLX_PATH) -lft $(MLX_FLAGS)
	@echo done!

bonus: $(BONUS_OBJECTS) $(LIBFT) $(MLX)
	@echo making so long
	@$(CC) $(CFLAGS) -g -o cub3D $(BONUS_OBJECTS) -L $(LIBFT_PATH) -L $(MLX_PATH) -lft $(MLX_FLAGS)
	@echo done!

$(MLX):
	@echo making minilibx....
	@echo -----------------------------------------
	@make --no-print-directory -C $(MLX_PATH)
	@echo -----------------------------------------
	@echo done!

$(LIBFT):
	@echo making libft....
	@make --no-print-directory -C $(LIBFT_PATH) $(LIBFT)
	@echo done!

$(OBJECTS): $(FILES)
	@$(CC) $(CFLAGS) -g -c $(FILES)

$(BONUS_OBJECTS): $(BONUS_FILES)
	@$(CC) $(CFLAGS) -g -c $(BONUS_FILES)

clean:
	@make --no-print-directory -C $(LIBFT_PATH) fclean
	@make --no-print-directory -C $(MLX_PATH) clean
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	@echo cleaning!
	@make --no-print-directory -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)
	@echo done!
	
re: fclean all 

.PHONY: all clean fclean re 