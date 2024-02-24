# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 13:22:14 by molasz-a          #+#    #+#              #
#    Updated: 2024/02/24 15:22:10 by molasz-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= fdf.c \
			image.c \
			parser.c

OBJS	= ${addprefix obj/, ${SRCS:.c=.o}}

DEPS	= ${addprefix obj/, ${SRCS:.c=.d}}

NAME	= fdf

RM		= rm -rf

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

LIBFT	= libs/libft/libft.a

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
				${CC} ${CFLAGS} -Ilibs/mlx -c $< -MMD -o $@
else
				${CC} ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< -MMD $@
endif

${NAME}:	${OBJS}
				@echo OS:${OS}
ifeq (${OS}, MAC)
				${CC} ${CFLAGS} -Llibs/mlx -lmlx -framework OpenGL -framework AppKit ${LIBFT} ${OBJS} -o ${NAME}
else
				${CC} ${CFLAGS} -lbsd -lmlx -lXext -lX11 ${LIBFT} ${OBJS} -o ${NAME}
endif

clean:
				make fclean -C libs/libft
				make clean -C libs/mlx
				${RM} obj/ 

fclean:		clean
				${RM} ${NAME}

re:			fclean all

-include ${DEPS}

.PHONY:		clean fclean re all linux
