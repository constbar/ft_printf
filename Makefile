# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agroup <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/15 16:15:10 by agroup            #+#    #+#              #
#    Updated: 2020/12/15 16:15:21 by agroup           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	ft_handle_adr_hex.c ft_handle_ddsz.c ft_handle_int_uint.c ft_handle_num.c \
			ft_handle_str_libft.c ft_output_char_str.c ft_output_num_sz.c ft_printf.c

OBJ		= ${SRC:.c=.o}

NAME	= libftprintf.a

CC		= gcc

RM		= rm -f

CF		= -Wall -Wextra -Werror

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
