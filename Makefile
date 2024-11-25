NAME = fractol

CC = cc
CFLAGS = #-Wall -Wextra -Werror

INCLUDES = includes/
MINILIB_DIR = minilibx-linux/
PRINTF_DIR = ft_printf/
SRC_DIR = src/
OBJ_DIR = obj/

SRC_FILES = main.c init_fractol.c render.c
OBJ_FILES = $(SRC_FILES:.c=.o)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

MLX = $(MINILIB_DIR)libmlx.a
PRINTF = $(PRINTF_DIR)libftprintf.a

all: $(MLX) $(PRINTF) $(NAME)

$(MLX):
	$(MAKE) -C $(MINILIB_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF) $(MLX) -ldl -lglfw -pthread -lm -lXext -lX11 -o $(NAME) 

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDES) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(MINILIB_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

flcean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: flcean all
