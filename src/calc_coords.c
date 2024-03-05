/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_coords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 23:15:21 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/05 23:46:38 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	calc_isometric(t_mlx *mlx, int z, t_point *p)
{
	p->x = (p->x - p->y) * cos(mlx->x_angle);
	p->y = (p->x + p->y) * sin(mlx->y_angle) - z * mlx->xy_scale;
}

static void	calc_prespective(int z, t_point *p)
{
	if (z > 0)
	{
		p->x /= z * tan(0.2);
		p->y /= z * tan(0.2);
	}
	else if (z < 0)
	{
		p->x = p->x / (-z * tan(0.2));
		p->y = p->y / (-z * tan(0.2));
	}
}

void	calc_coords(t_mlx *mlx)
{
	int	x;
	int	y;
	int	z;

	y = 0;
	while (y < mlx->y_max)
	{
		x = 0;
		while (x < mlx->x_max)
		{
			z = mlx->coords[y][x].z * mlx->z_scale;
			mlx->points[y][x].x = mlx->coords[y][x].x * mlx->xy_scale;
			mlx->points[y][x].y = mlx->coords[y][x].y * mlx->xy_scale;
			if (!mlx->projection)
				calc_isometric(mlx, z, &mlx->points[y][x]);
			else
				calc_prespective(z, &mlx->points[y][x]);
			mlx->points[y][x].x += mlx->x_shift;
			mlx->points[y][x].y += mlx->y_shift;
			x++;
		}
		y++;
	}
}
