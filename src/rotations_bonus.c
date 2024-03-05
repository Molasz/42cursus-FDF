/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 01:37:32 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/05 00:56:07 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	rotation_x(t_mlx *mlx)
{
	t_coord	coord;
	int		x;
	int		y;

	y = -1;
	while (++y < mlx->y_max)
	{
		x = -1;
		while (++x < mlx->x_max)
		{
			coord.x = mlx->coords[y][x].x * cos(0.8)
				- mlx->coords[y][x].y * sin(0.8);
			coord.y = mlx->coords[y][x].y * sin(0.8)
				+ mlx->points[y][x].x * cos(0.8);
			mlx->coords[y][x].x = coord.x;
			mlx->coords[y][x].y = coord.y;
		}
	}
}

void	rotation(t_mlx *mlx, int n)
{
	(void) n;
	rotation_x(mlx);
}
