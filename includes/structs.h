/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:17:30 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/05 02:41:30 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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
	int				x;
	int				y;
	int				z;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}			t_coord;

typedef struct s_point
{
	int	x;
	int	y;
}			t_point;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	*img;
	t_img	*menu;
	t_coord	**coords;
	t_point	**points;
	int		width;
	int		height;
	int		x_max;
	int		y_max;
	int		z_max;
	int		z_min;
	int		x_shift;
	int		y_shift;
	float	x_angle;
	float	y_angle;
	float	xy_scale;
	float	z_scale;
	int		projection;
	int		triangles;
}			t_mlx;

typedef struct s_foint
{
	float	x;
	float	y;
}			t_foint;

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
	float	dr;
	float	dg;
	float	db;
}				t_color;

#endif
