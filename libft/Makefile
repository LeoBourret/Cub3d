SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_double_strlen.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
		ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c   \
		ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
		ft_realloc.c ft_realloc_double.c ft_strcmp.c  \
		ft_lstnew.c 		\
		ft_lstadd_front.c 	\
		ft_lstadd_back.c 	\
		ft_lstclear.c 		\
		ft_lstdelone.c 		\
		ft_lstiter.c		\
		ft_lstlast.c		\
		ft_lstmap.c			\
		ft_lstsize.c

MAKEFLAGS += --no-print-directory

OBJ = $(SRC:.c=.o)

PFT_DIR = ft_printf/

OBJ_PFT = ft_printf/srcs/ft_display.o \
			ft_printf/srcs/ft_manage_addr.o\
			ft_printf/srcs/ft_manage_char.o \
			ft_printf/srcs/ft_manage_char.o \
			ft_printf/srcs/ft_manage_flags.o \
			ft_printf/srcs/ft_manage_hex.o \
			ft_printf/srcs/ft_manage_int.o \
			ft_printf/srcs/ft_manage_uint.o \
			ft_printf/srcs/ft_manage_percent.o \
			ft_printf/srcs/ft_manage_str.o \
			ft_printf/srcs/ft_manage_type.o \
			ft_printf/srcs/ft_manage_width.o \
			ft_printf/srcs/ft_manager.o \
			ft_printf/srcs/ft_printf.o \
			ft_printf/srcs/ft_tools.o \
			ft_printf/srcs/ft_tools2.o

LOCATION = $(addprefix $(PFT_DIR), $(OBJ_PFT))

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

pft:
		@make -C ft_printf

$(NAME): pft $(OBJ)
		@ar rcs $(NAME) $(OBJ) $(OBJ_PFT)


clean:
		@$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
		@$(RM) $(NAME)
		@make clean -C ft_printf/

re: fclean all

.PHONY: clean fclean bonus
