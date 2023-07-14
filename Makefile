NAME = pipex.a

LIBFTPRINTF = ./ft_printf/libftprintf.a

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC = 

OBJ = $(SRC:.=.o)

$(NAME): ${OBJ}
		make -C ./ft_printf
		cp ${LIBFTPRINTF} ${NAME}
		ar rc ${NAME} ${OBJ}

all:	$(NAME) clean

clean:
		${MAKE} clean  -C ./ft_printf
		$(RM) ${OBJ}

fclean:	clean
		${MAKE} fclean -C ./ft_printf
		$(RM) $(NAME)

re:	fclean