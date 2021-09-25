NAME = so_long
LIBFT = libft.a
MLX = libmlx.a

LIBFT_PATH = ./libs/libft/
MLX_PATH = ./libs/minilibx-linux/

SRC = ./src/mandatory/

FILES = $(SRC)solong.c $(SRC)key_functions.c $(SRC)generate_screen.c \
$(SRC)parse_map.c $(SRC)color_text.c $(SRC)error_messages.c $(SRC)map_utils.c \
$(SRC)map_read.c
OBJECTS = solong.o key_functions.o generate_screen.o parse_map.o color_text.o \
	error_messages.o map_utils.o map_read.o

CC = clang
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lm -lbsd -lmlx -lXext -lX11
RE = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)
	make --no-print-directory -C $(MLX_PATH)
	make --no-print-directory -C $(LIBFT_PATH) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -L $(LIBFT_PATH) -L $(MLX_PATH) -lft $(MLX_FLAGS)

$(OBJECTS): $(FILES)
	$(CC) $(CFLAGS) -g -c $(FILES)

clean:
	make --no-print-directory -C $(LIBFT_PATH) fclean
	make --no-print-directory -C $(MLX_PATH) clean
	$(RM) $(OBJECTS)

fclean: clean
	echo cleaning!
	make --no-print-directory -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)
	echo done!
	
re: fclean all 

.PHONY: all clean fclean re 