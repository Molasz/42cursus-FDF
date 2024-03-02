/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:17:30 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/02 15:48:32 by molasz-a         ###   ########.fr       */
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
	t_img	*menu;
	t_coord	**coords;
	int		width;
	int		height;
	int		x_max;
	int		y_max;
	int		z_max;
	int		x_shift;
	int		y_shift;
	float	x_angle;
	float	y_angle;
	float	xy_scale;
	float	z_scale;
	int		projection;
}			t_mlx;

typedef struct s_point
{
	int	x;
	int	y;
}			t_point;

typedef struct s_foint
{
	float	x;
	float	y;
}			t_foint;

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	float			dr;
	float			dg;
	float			db;
}			t_color;
#endif
