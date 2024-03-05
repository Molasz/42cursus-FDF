/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_coords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 23:15:21 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/04 16:15:29 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	calc_isometric(t_mlx *mlx, int x, int y, t_point *p)
{
	int	z;

	z = mlx->coords[y][x].z * mlx->z_scale * mlx->xy_scale;
	p->x = mlx->coords[y][x].x * mlx->xy_scale;
	p->y = mlx->coords[y][x].y * mlx->xy_scale;
	p->x = (p->x - p->y) * cos(mlx->x_angle);
	p->y = (p->x + p->y) * sin(mlx->y_angle) - z;
	p->x += mlx->x_shift;
	p->y += mlx->y_shift;
}

static void	calc_prespective(t_mlx *mlx, int x, int y, t_point *p)
{
	double	ar;
	double	f;
	double	lam;
	double	nlam;
	double	z;

	ar = mlx->height / mlx->width;
	f = 1 / tan(0.25 / 2);
	lam = mlx->z_max / (mlx->z_max - mlx->z_min);
	nlam = -(mlx->z_max * mlx->z_min) / (mlx->z_max - mlx->z_min);
	z = lam * mlx->coords[y][x].z - nlam * mlx->z_min;
	p->x *= ar * f;
	p->y *= f;
	printf("[%d, %d, %f]\n", p->x, p->y, z);
}

void	calc_coords(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < mlx->y_max)
	{
		x = 0;
		while (x < mlx->x_max)
		{
			if (!mlx->projection)
				calc_isometric(mlx, x, y, &mlx->points[y][x]);
			else
				calc_prespective(mlx, x, y, &mlx->points[y][x]);
			x++;
		}
		y++;
	}
}
