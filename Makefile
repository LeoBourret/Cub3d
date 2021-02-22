SRCS_DIR = srcs/

MLX = -L ./minilibx-linux -lmlx -lXext  -lX11 -lm -lbsd 

NAME = cub3D

CFLAGS = -Wall -Wextra -Werror -g $(INC)

HEADER_DIR = ./incs 

SRCS_FILES = 	color_manager.c \
	move_manager.c \
	move_manager_re.c \
	engine.c \
	engine_init.c \
	sorter.c \
	key_manager.c \
	main.c \
	sprite_manager.c \
	texture_manager.c \
	checker.c \
	error.c \
	exit.c \
	get_next_line.c \
	parser.c \
	parser_utils1.c \
	parser_utils2.c \
	manage_args.c \
	save.c \
	memory.c \
	init.c

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJSRCS = $(SRCS:.c=.o) 

INC = -I $(HEADER_DIR) -I ./minilibx-linux -I ./libft

$(NAME) : $(OBJSRCS)
	@echo "\033[33m[Libft and MLX compilation...]"
	@make -C libft
	@make -C minilibx-linux
	@echo "\033[33m[Remove last version...]"
	@rm -rf cub3D
	@echo "\033[33m[Cub3D compilation...]"
	@gcc  $(OBJSRCS) -L ./libft -lft $(MLX) -o $(NAME) $(INC)
	@echo "\033[33m[Done !]"

all : $(NAME)

clean :
	@rm -rf $(OBJSRCS)

fclean : clean
	@rm -rf $(NAME)
	@rm -rf cub3d.bmp

re : fclean all
