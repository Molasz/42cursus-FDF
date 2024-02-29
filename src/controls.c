/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:15:54 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/29 22:25:44 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	on_close(t_mlx *mlx)
{
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img->img);
	free_coords(mlx);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return (0);
}

int	on_key(int n, t_mlx *mlx)
{
	if (n == 53)
	{
		on_close(mlx);
		return (0);
	}
	else if (n == 123)
		mlx->x_shift -= 10;
	else if (n == 124)
		mlx->x_shift += 10;
	else if (n == 125)
		mlx->y_shift += 10;
	else if (n == 126)
		mlx->y_shift -= 10;
	else if (n == 18 && mlx->angle != 360)
		mlx->angle += 10;
	else if (n == 19 && mlx->angle != 0)
		mlx->angle -= 10;
	else
	{
		printf("%d\n", n);
		return (0);
	}
	new_image(mlx, mlx->img);
	return (0);
}

int	on_mouse(int button, int x, int y, t_mlx *mlx)
{
	printf("%d %d %d %p\n", button, x, y, mlx);
	return (0);
}
