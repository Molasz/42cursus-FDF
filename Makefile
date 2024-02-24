# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 13:22:14 by molasz-a          #+#    #+#              #
#    Updated: 2024/02/24 11:22:35 by molasz-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= fdf.c \
			image.c \
			parser.c

OBJS	= ${addprefix obj/, ${SRCS:.c=.o}}

DEPS	= ${addprefix obj/, ${SRCS:.c=.d}}

NAME	= fdf

AR		= ar rcs

RM		= rm -f

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

OS		= MAC

all:		dir ${NAME}

linux:		
				${MAKE} OS=LINUX all

dir:
				mkdir -p obj
				make -C libs/libft

ifeq (${OS}, MAC)
				make -C libs/mlx
else
				make -C libs/mlx_linux
endif

obj/%.o:		src/%.c Makefile
ifeq (${OS}, MAC)
				${CC} ${CFLAGS} -Imlx -c $< -MMD
else
				${CC} ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< -MMD
endif

${NAME}:	${OBJS}
				@echo OS:${OS}
ifeq (${OS}, MAC)
				${CC} ${CFLAGS} -Lmlx -lmlx -framework OpenGL -framework AppKit ${OBJS} -o ${NAME}
else
				${CC} ${CFLAGS} -lbsd -lmlx -lXext -lX11 -o ${NAME}
endif

clean:
				make clean -C libs/mlx
				make clean -C libs/mlx_linux
				make fclean -C libs/libft
				${RM} obj/ 

fclean:		clean
				${RM} ${NAME}

re:			fclean all

-include ${DEPS}

.PHONY:		clean fclean re all linux
