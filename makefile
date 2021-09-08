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

FILES = $(SRC)solong.c $(SRC)handle_window.c $(SRC)generate_screen.c $(SRC)parse_map.c \
$(SRC)color_text.c $(SRC)error_messages.c
OBJECTS = solong.o handle_window.o generate_screen.o parse_map.o color_text.o \
	error_messages.o

CC = clang
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lm -lbsd -lmlx -lXext -lX11
RE = rm -f

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) $(MLX)
	@echo -ne 'making so long: ####                      (16%)\r'
	@sleep 1
	@echo -ne 'making so long: ########                  (33%)\r'
	@sleep 1
	@echo -ne 'making so long: #############             (66%)\r'
	@sleep 1
	@echo -ne 'making so long: ###################       (78%)\r'
	@sleep 1
	@echo -ne 'making so long: ##########################(100%)\r'
	@echo -ne '\n'
	@$(CC) $(CFLAGS) -g -o $(NAME) $(OBJECTS) -L $(LIBFT_PATH) -L $(MLX_PATH) -lft $(MLX_FLAGS)
	@echo done!

bonus: $(BONUS_OBJECTS) $(LIBFT) $(MLX)
	@echo making so long
	@$(CC) $(CFLAGS) -g -o solong $(BONUS_OBJECTS) -L $(LIBFT_PATH) -L $(MLX_PATH) -lft $(MLX_FLAGS)
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