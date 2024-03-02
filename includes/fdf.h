/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:28:25 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/03 00:00:58 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libs/libft/libft.h"
# include "../libs/mlx/mlx.h"
# include "structs.h"
# include "enums.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>

# define WIN_SIZE 1280

void	free_coords(t_mlx *mlx);
int		parser_limits(char *f, t_mlx *mlx);
int		parser(char *f, t_mlx *mlx);
int		new_image(t_mlx *mlx, t_img *img);
void	calc_color(t_mlx *mlx, t_color *color, t_point start, t_point end);
void	draw_line(t_mlx *mlx, t_point start, t_point end, t_color *color);
void	controls(t_mlx *mlx);
int		new_menu(t_mlx *mlx, t_img *menu);
int		on_close(t_mlx *mlx);
int		on_key(int n, t_mlx *mlx);


# ifdef BONUS

int		on_mouse(int n, int x, int y, t_mlx *mlx);
void	on_key_bonus(int n, t_mlx *mlx);
void	on_mouse_bonus(int n, t_mlx *mlx);

# endif

#endif
