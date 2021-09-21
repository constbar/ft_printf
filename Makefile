NAME	= libftprintf.a

SRC		=	src/ft_handle_adr_hex.c src/ft_handle_ddsz.c src/ft_handle_int_uint.c src/ft_handle_num.c \
			src/ft_handle_str_libft.c src/ft_output_char_str.c src/ft_output_num_sz.c src/ft_printf.c

CC		= gcc

CF		= -Wall -Wextra -Werror

OBJ		= ${SRC:.c=.o}

RM		= rm -f

.c.o:
			${CC} ${CF} -c $< -o ${<:.c=.o}

$(NAME):	${OBJ}
			ar rc ${NAME} ${OBJ}
			ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJ}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
