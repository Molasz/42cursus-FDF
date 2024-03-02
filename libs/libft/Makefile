# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 19:20:08 by molasz-a          #+#    #+#              #
#    Updated: 2024/03/03 00:34:59 by molasz-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_atoi.c \
			ft_itoa.c \
			get_next_line.c \
			get_next_line_utils.c

OBJS	= ${SRCS:.c=.o}

DEPS	= ${SRCS:.c=.d}

NAME	= libft.a

AR		= ar rcs

RM		= rm -f

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

all: 		${NAME}

%.o:		%.c
				${CC} ${CFLAGS} -c $< -MMD

${NAME}:	${OBJS} Makefile
				${AR} ${NAME} ${OBJS}

clean:
				${RM} ${OBJS} ${DEPS}

fclean:		clean
				${RM} ${NAME}

re:			fclean all

-include ${DEPS}

.PHONY:		clean fclean re all bonus
