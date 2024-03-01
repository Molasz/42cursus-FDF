# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 13:22:14 by molasz-a          #+#    #+#              #
#    Updated: 2024/03/01 15:41:14 by molasz-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= fdf.c \
			parser_limits.c \
			parser.c \
			image.c \
			draw_line.c \
			controls.c

BSRCS	= controls_bonus.c

OBJS	= ${addprefix obj/, ${SRCS:.c=.o}}

BOBJS	= ${addprefix obj/, ${BSRCS:.c=.o}}

DEPS	= ${addprefix obj/, ${SRCS:.c=.d}}

BDEPS	= ${addprefix obj/, ${BSRCS:.c=.d}}

NAME	= fdf

RM		= rm -rf

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

MXFLAGS	= -Llibs/mlx -lmlx -framework OpenGL -framework AppKit

LIBFT	= libs/libft/libft.a

MLXLIB	= mlx

all:		dir ${NAME}

linux:
				${MAKE} LINUX=1 MLXLIB=mlx_linux MXFLAGS="libs/mlx_linux/libmlx.a -lXext -lX11 -lm -lz" all

bonus:
				${MAKE} BONUS=1 all

linuxb:
				${MAKE} BONUS=1 linux

dir:
				mkdir -p obj
				make -C libs/libft
				make -C libs/${MLXLIB}

obj/%.o:	src/%.c Makefile
ifdef BONUS
ifdef LINUX
				${CC} ${CFLAGS} -c $< -MMD -o $@ -D BONUS=1 -D LINUX=1
else
				${CC} ${CFLAGS} -c $< -MMD -o $@ -D BONUS=1
endif
else
ifdef LINUX
				${CC} ${CFLAGS} -c $< -MMD -o $@ -D LINUX=1
else
				${CC} ${CFLAGS} -c $< -MMD -o $@
endif
endif

ifdef BONUS
${NAME}:	${OBJS} ${BOBJS} dir
				${CC} ${CFLAGS} ${OBJS} ${BOBJS} ${LIBFT} ${MXFLAGS} -o ${NAME}
else
${NAME}:	${OBJS} dir
				${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${MXFLAGS} -o ${NAME}
endif

clean:
				make fclean -C libs/libft
				make clean -C libs/mlx
				${RM} obj/

fclean:		clean
				${RM} ${NAME}

re:			fclean all

-include ${DEPS} ${BDEPS}

.PHONY:		clean fclean re all linux bonus linuxb
