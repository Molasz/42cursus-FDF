# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 13:22:14 by molasz-a          #+#    #+#              #
#    Updated: 2024/02/22 23:58:38 by molasz-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= fdf.c \
			image.c

OBJS	= ${SRCS:.c=.o}

DEPS	= ${SRCS:.c=.d}

NAME	= fdf

AR		= ar rcs

RM		= rm -f

CC		= clang

CFLAGS	= -Wall -Wextra -Werror

OS		= MAC

all:		${NAME}

linux:		
				${MAKE} OS=LINUX all

%.o:		%.c Makefile
ifeq (${OS}, MAC)
				${CC} ${CFLAGS} -Imlx -c $< -MMD
else
				${CC} ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< -MMD
endif

${NAME}:	${OBJS}
ifeq (${OS}, MAC)
				make -C mlx
				${CC} ${CFLAGS} -Lmlx -lmlx -framework OpenGL -framework AppKit ${OBJS} -o ${NAME}
else
				make -C mlx_linux
				${CC} ${CFLAGS} -lbsd -lmlx -lXext -lX11 -o ${NAME} -v
endif

clean:
				make clean -C mlx
				make clean -C mlx_linux
				${RM} ${OBJS} ${DEPS}

fclean:		clean
				${RM} ${NAME}

re:			fclean all

-include ${DEPS} ${BDEPS}

.PHONY:		clean fclean re all linux
