/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:28:25 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/29 20:30:26 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libs/libft/libft.h"
# include "../libs/mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>

# define SIZE 1000

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_coord
{
	int				z;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}			t_coord;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	*img;
	t_coord	**coords;
	int		max_x;
	int		max_y;
	int		width;
	int		height;
	int		angle;
	float	scale;
	int		zscale;
	int		x_shift;
	int		y_shift;
}			t_mlx;

typedef struct s_point
{
	int	x;
	int	y;
}			t_point;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	dr;
	int	dg;
	int	db;
}			t_color;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

void	free_coords(t_mlx *mlx);
int		parser_limits(char *f, t_mlx *mlx);
int		parser(char *f, t_mlx *mlx);

int		new_image(t_mlx *mlx, t_img *img);

void	draw_line(t_mlx *mlx, t_point start, t_point end, t_color *color);

#endif
