# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 13:22:14 by molasz-a          #+#    #+#              #
#    Updated: 2024/02/29 22:20:04 by molasz-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= fdf.c \
			parser_limits.c \
			parser.c \
			image.c \
			draw_line.c \
			controls.c

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

obj/%.o:	src/%.c Makefile
				${CC} ${CFLAGS} -c $< -MMD -o $@

${NAME}:	${OBJS} dir
				@echo OS:${OS}
ifeq (${OS}, MAC)
				${CC} ${CFLAGS} ${OBJS} ${LIBFT} -Llibs/mlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}
else
				${CC} ${CFLAGS} ${OBJS} ${LIBFT} libs/mlx_linux/libmlx.a -lXext -lX11 -lm -lz -o ${NAME}
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
