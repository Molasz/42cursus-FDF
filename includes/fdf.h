/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:28:25 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/25 00:41:06 by molasz-a         ###   ########.fr       */
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

# define WIDTH 1280
# define HEIGHT 720
# define SPACE 100

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_mlx
{
	t_list	*coords;
	void	*mlx;
	void	*win;
	t_img	*img;
}			t_mlx;

typedef struct s_point
{
	int	x;
	int	y;
}			t_point;

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

t_list	*parser(char *f);

int		new_image(t_mlx *mlx, t_img *img);
void	put_pixel(t_img *img, int x, int y, int color);

void	draw_line(t_img *img, t_point start, t_point end);

#endif
