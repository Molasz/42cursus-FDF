# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 13:22:14 by molasz-a          #+#    #+#              #
#    Updated: 2024/02/21 17:36:50 by molasz-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= fdf.c

OBJS	= ${SRCS:.c=.o}

DEPS	= ${SRCS:.c=.d}

NAME	= fdf

AR		= ar rcs

RM		 = rm -f

CC		 = gcc

CFLAGS	= -Wall -Wextra -Werror 

all:		${NAME}

%.o:		%.c Makefile
				${CC} ${CFLAGS} -Imlx -c $< -MMD

${NAME}:	${OBJS}
				make -C mlx
				${CC} ${CFLAGS} -Lmlx -lmlx -framework OpenGL -framework AppKit ${OBJS} -o ${NAME}

clean:
				make clean -C mlx
				${RM} ${OBJS} ${DEPS}

fclean:		clean
				make fclean -C mlx 
				${RM} ${NAME}

re:			fclean all

-include ${DEPS} ${BDEPS}

.PHONY:		clean fclean re all
