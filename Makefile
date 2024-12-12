NAME        = fract-ol

CC          = gcc
CFLAGS      = -Werror -Wextra -Wall

MLX_PATH    = minilibx/
MLX_NAME    = libmlx.a
MLX         = $(MLX_PATH)$(MLX_NAME)

LIBFT_PATH  = libft/_libft/
LIBFT_NAME  = libft.a
LIBFT       = $(LIBFT_PATH)$(LIBFT_NAME)

PRINTF_PATH  = libft/ft_printf/
PRINTF_NAME  = libftprintf.a
PRINTF      = $(PRINTF_PATH)$(PRINTF_NAME)

INC         = -I ./libft/ -I ./minilibx/

SRC         = fractal.c hook.c init_stuff.c mandelbrot.c
OBJ         = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJ) $(MLX) $(LIBFT) $(PRINTF)
	@echo "Compiling fract-ol..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) $(LIBFT) $(PRINTF) $(INC) -framework OpenGL -framework AppKit
	@echo "Fract-ol ready"

$(MLX):
	@echo "Making MiniLibX..."
	@make -sC $(MLX_PATH)

$(LIBFT):
	@echo "Making libft..."
	@make -sC $(LIBFT_PATH)

$(PRINTF):
	@echo "Making printf..."
	@make -sC $(PRINTF_PATH)

bonus: all

clean:
	@echo "Removing .o object files..."
	@rm -f $(OBJ)
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(PRINTF_PATH)

fclean: clean
	@echo "Removing fract-ol..."
	@rm -f $(NAME)


re: fclean all

.PHONY: all re clean fclean
