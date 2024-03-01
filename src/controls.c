/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:15:54 by molasz-a          #+#    #+#             */
/*   Updated: 2024/03/01 13:13:33 by molasz-a         ###   ########.fr       */
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

#ifndef BONUS

int	on_key(int n, t_mlx *mlx)
{
	if (n == 53)
	{
		on_close(mlx);
		return (0);
	}
	return (0);
}
#else

int	on_key(int n, t_mlx *mlx)
{
	if (n == 53)
	{
		on_close(mlx);
		return (0);
	}
	on_key_bonus(n, mlx);
	return (0);
}
#endif

int	on_mouse(int button, int x, int y, t_mlx *mlx)
{
	printf("%d %d %d %p\n", button, x, y, mlx);
	return (0);
}
