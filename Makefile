# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 13:22:14 by molasz-a          #+#    #+#              #
#    Updated: 2024/03/04 01:38:35 by molasz-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= fdf.c \
			parser_limits.c \
			parser.c \
			image.c \
			calc_coords.c \
			draw_line.c \
			controls.c \
			controls_events.c \
			menu.c \
			menu_utils.c

BSRCS	= controls_bonus.c \
			rotations_bonus.c

OBJS	= ${addprefix obj/, ${SRCS:.c=.o}}

BOBJS	= ${addprefix obj/, ${BSRCS:.c=.o}}

DEPS	= ${addprefix obj/, ${SRCS:.c=.d}}

BDEPS	= ${addprefix obj/, ${BSRCS:.c=.d}}

NAME	= fdf

RM		= rm -rf

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

MXFLAGS	= -Llibs/mlx -lmlx -framework OpenGL -framework AppKit -lm

LIBFT	= libs/libft/libft.a

MLXLIB	= mlx

all:		dir ${NAME}

ifndef BONUS

${NAME}:	${OBJS} dir
				${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${MXFLAGS} -o ${NAME}

else

${NAME}:	${OBJS} ${BOBJS} dir
				${CC} ${CFLAGS} ${OBJS} ${BOBJS} ${LIBFT} ${MXFLAGS} -o ${NAME}

endif

linux:
				make LINUX=1 MLXLIB=mlx_linux MXFLAGS="libs/mlx_linux/libmlx.a -lXext -lX11 -lm -lz" all

bonus:
				make BONUS=1 all

lbonus:
				make BONUS=1 linux

dir:
				mkdir -p obj
				make -C libs/libft
				make -C libs/${MLXLIB}

obj/%.o:	src/%.c Makefile

ifndef BONUS

 ifndef LINUX

				${CC} ${CFLAGS} -c $< -MMD -o $@

 else

				${CC} ${CFLAGS} -c $< -MMD -o $@ -D LINUX=1

 endif

else

 ifndef LINUX

				${CC} ${CFLAGS} -c $< -MMD -o $@ -D BONUS=1

 else

				${CC} ${CFLAGS} -c $< -MMD -o $@ -D BONUS=1 -D LINUX=1

 endif

endif

clean:
				${RM} obj/

lclean:
				make MLXLIB=mlx_linux fclean

fclean:		clean
				make fclean -C libs/libft
				make clean -C libs/${MLXLIB}
				${RM} ${NAME}

re:			fclean all

-include ${DEPS} ${BDEPS}

.PHONY:		clean fclean re all linux bonus lbonus lclean
