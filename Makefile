NAME = pipex

LIBFT = ./libft/libft.a

CFLAGS = -Wall -Wextra -Werror

SRC =	pipex.c \
		utils.c

OBJ = $(SRC:.c=.o)

$(NAME): ${OBJ}
		make all -C ./libft
		cc $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)
		make clean

all:	$(NAME)

clean:
		${MAKE} clean  -C ./libft
		rm -f ${OBJ}

fclean:	clean
		${MAKE} fclean -C ./libft
		rm -f $(NAME)

re:	fclean all