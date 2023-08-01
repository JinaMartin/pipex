NAME = pipex

LIBFTPRINTF = ./ft_printf/libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRC =	pipex.c \
		utils.c

OBJ = $(SRC:.c=.o)

$(NAME): ${OBJ}
		make -C ./ft_printf
		cp ${LIBFTPRINTF} ${NAME}
		ar rc ${NAME} ${OBJ}
		${MAKE} clean
		chmod +x ${NAME}

all:	$(NAME) clean

clean:
		${MAKE} clean  -C ./ft_printf
		rm -f ${OBJ}

fclean:	clean
		${MAKE} fclean -C ./ft_printf
		rm -f $(NAME)

re:	fclean all