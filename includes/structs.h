/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:17:30 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/01 13:25:10 by molasz-a         ###   ########.fr       */
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
#endif
